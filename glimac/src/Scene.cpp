//
// Created by koro on 15/12/15.
//

#include "Scene.hpp"

namespace glimac{
    //HACK : ratio should be retrieved
    Scene::Scene ()
        : mCamera(new FreeflyCamera(glm::perspective(glm::radians(40.0f), 1280.0f/720.0f, 0.1f, 10000.0f))),
          mCurrentProgramId(0),
          mDirLight(new Light(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f))),
          mSkybox(std::unique_ptr<Skybox>(new Skybox))
    { }

    Scene::~Scene () {
        std::cout << "Deleting scene" << std::endl;
        for(auto renderable: mRenderables){
            delete renderable;
        }
        for(auto program: mPrograms){
            delete program;
        }
        for(auto light: mPointLights){
            delete light;
        }

        delete mDirLight;
        delete mCamera;

    }

    void Scene::update () {
        for(auto renderable: mRenderables){
            renderable->update();
        }
    }

    void Scene::render () {
        glm::mat4 view = mCamera->getViewMatrix();
        mCurrentProgram->setUniformMatrix4("view", view);

        mSkybox->draw(mCamera->getProjectionMatrix(), view);

        mCurrentProgram->use();
        for(auto renderable: mRenderables){
            renderable->render(mCurrentProgram);
        }
    }

    void Scene::addRenderable (Renderable *renderable) {
        mRenderables.push_back(renderable);
    }




    Scene::Scene (std::string &path)
            : Scene() {
        std::string fullPath = "assets/scenes/" + path;
        std::ifstream ifs(fullPath);
        if (!ifs.is_open())
            throw std::runtime_error("couldnt load file");

        std::stringstream buffer;
        buffer << ifs.rdbuf();
        Document document;
        document.Parse(buffer.str().c_str());

        const Value &camera = document["camera"];
        const Value &models = document["models"];
        const Value &dirLights = document["lights"]["directional"];
        const Value &pointLights = document["lights"]["point"];
        //const Value &programs = document["programs"];

        // 1/5 : set Camera position
        mCamera->setPosition(camera["position"]["x"].GetDouble(), camera["position"]["y"].GetDouble(),
                             camera["position"]["z"].GetDouble());

        // 2/5 : create renderables
        for (SizeType i = 0; i < models.Size(); ++i) {
            const Value &pos = models[i]["position"];
            const Value &rot = models[i]["rotation"];
            const Value &scale = models[i]["scale"];
            std::string type = models[i]["type"].GetString();
            Renderable *r = RenderableFactory::getByName(type);

            r->setPosition(glm::vec3(pos["x"].GetDouble(), pos["y"].GetDouble(), pos["z"].GetDouble()));
            r->setRotation(rot["x"].GetDouble(), rot["y"].GetDouble(), rot["z"].GetDouble());
            r->setScale(glm::vec3(scale["x"].GetDouble(), scale["y"].GetDouble(), scale["z"].GetDouble()));
            addRenderable(r);
        }
        std::cout << "added renderables" << std::endl;

        // 3/5 : create dir lights
        setDirLight(glm::vec3(dirLights["direction"]["x"].GetDouble(),
                              dirLights["direction"]["y"].GetDouble(),
                              dirLights["direction"]["z"].GetDouble()),
                    glm::vec3(1.0f, 1.0f, 1.0f));

        std::cout << "added dirLight" << std::endl;

        // 4/5 : create points lights

        for (SizeType i = 0; i < pointLights.Size(); i++) {
            const Value &pos = pointLights[i]["position"];
            const Value &col = pointLights[i]["color"];
            //double intensity = dirLights[i]["intensity"].GetDouble();

            glm::vec3 posVec = glm::vec3(pos["x"].GetDouble(),
                                         pos["y"].GetDouble(),
                                         pos["z"].GetDouble());
            glm::vec3 colVec = glm::vec3(col["r"].GetDouble(),
                                         col["g"].GetDouble(),
                                         col["b"].GetDouble());
            addPointLight(new Light(posVec, colVec));
        }

        std::cout << "added lights from the scene" << std::endl;
        //5/5 : create programs
        /*
        for (SizeType i = 0; i < programs.Size(); ++i)
        {
            std::string name = programs[i]["name"].GetString();
            std::string vs_path = programs[i]["vs_path"].GetString();
            std::string fs_path = programs[i]["fs_path"].GetString();

            Program * p = loadProgram(vs_path.c_str(), fs_path.c_str());
            addProgram(p);
        }
        */


        loadPrograms();
        std::cout << "added everything from the scene" << std::endl;
    }

    std::vector<Light *> & Scene::getPointLights(){
        return mPointLights;
    }



    void Scene::addPointLight(Light * light){
        mPointLights.push_back(light);
    }

    void Scene::loadPrograms () {
        //TODO : more shaders ?
        Program * p  = glimac::loadProgram("shaders/3D.vs.glsl", "shaders/3D.fs.glsl");
        addProgram(p);
        Program * cs = glimac::loadProgram("shaders/3D.vs.glsl", "shaders/cellshading.fs.glsl");
        addProgram(cs);
        setProgram(p);

    }

    void Scene::addProgram (Program * program) {
        mPrograms.push_back(program);
    }

    void Scene::setProgram (Program * program) {
        mCurrentProgram = program;
        mCurrentProgram->use();
        mCurrentProgram->setUniformMatrix4("projection", mCamera->getProjectionMatrix());
        createLightsUniforms();

    }

    Program *Scene::getCurrentProgram () {
        return mCurrentProgram;
    }

    FreeflyCamera* Scene::getCamera () {
        return mCamera;
    }

    std::vector<Renderable *> & Scene::getRenderables () {
        return mRenderables;
    }



    void Scene::setDirLight(glm::vec3 dir, glm::vec3 color) {
        mDirLight->setLightPos(dir);
        mDirLight->setLightColor(color);
    }

    void Scene::createLightsUniforms() {

        //DIRECTIONAL LIGHT
        mCurrentProgram->setUniform("myDirLight.lightDir", mDirLight->getLightPos());
        mCurrentProgram->setUniform("myDirLight.lightColor", mDirLight->getLightColor());

        //POINT LIGHTS
        mCurrentProgram->setUniformInt("nbPointLights", mPointLights.size());

        for(unsigned int i = 0; i < mPointLights.size(); i++){

            std::string currUniformName = "lights[";
            currUniformName += std::to_string(i);

            std::string uniformColor = (currUniformName+"].lightColor").c_str();
            std::string uniformPos = (currUniformName+"].lightPos").c_str();

            mCurrentProgram->setUniform(uniformColor.c_str(), mPointLights[i]->getLightColor());
            mCurrentProgram->setUniform(uniformPos.c_str(), mPointLights[i]->getLightPos());

        }
    }

    void Scene::useNextShader () {
        if(mCurrentProgramId + 1 >= mPrograms.size()){
            setProgram(mPrograms.at(0));
            mCurrentProgramId = 0;
        }
        else{
            setProgram(mPrograms.at(++mCurrentProgramId));
        }
    }
}