//
// Created by koro on 15/12/15.
//

#include "Scene.hpp"

namespace glimac{
    //HACK : ratio should be retrieved
    Scene::Scene ()
        : mCamera(new FreeflyCamera(glm::perspective(glm::radians(40.0f), 1280.0f/720.0f, 0.1f, 100.0f)))
    {
        loadPrograms();
        std::cout << "Program added has ID " << mPrograms.at(0)->getGLId() << std::endl;
        setProgram(mPrograms.at(0));


        mCurrentProgram->setUniformMatrix4("projection", mCamera->getProjectionMatrix());
        //mCamera->moveFront(-1.0f);
    }

    Scene::~Scene () {
        for(auto renderable: mRenderables){
            delete renderable;
        }
        for(auto program: mPrograms){
            delete program;
        }
    }

    void Scene::update () {
        for(auto renderable: mRenderables){
            renderable->update();
        }
    }

    void Scene::render () {
        glm::mat4 view = mCamera->getViewMatrix();
        mCurrentProgram->setUniformMatrix4("view", view);

        for(auto renderable: mRenderables){
            renderable->render(mCurrentProgram);
        }
    }

    void Scene::addRenderable (Renderable *renderable) {
        mRenderables.push_back(renderable);
    }

    void Scene::loadPrograms () {
        //TODO : more shaders ?
        Program * p  = glimac::loadProgram("shaders/3D.vs.glsl", "shaders/3D.fs.glsl");
        addProgram(p);
        std::cout << "mprograms has " << mPrograms.size() << std::endl;

    }

    void Scene::addProgram (Program * program) {
        mPrograms.push_back(program);
    }

    void Scene::setProgram (Program * program) {
        mCurrentProgram = program;
        mCurrentProgram->use();
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

    Scene::Scene (std::string &path)
        : Scene()
    {
        std::string fullPath = "assets/scenes/" + path;
        std::ifstream ifs(fullPath);
        if(!ifs.is_open())
            throw std::runtime_error("couldnt load file");

        std::stringstream buffer;
        buffer << ifs.rdbuf();
        Document document;
        document.Parse(buffer.str().c_str());

        const Value& camera = document["camera"];
        const Value& models = document["models"];
        //const Value& lights = document["lights"];
        //const Value& programs = document["programs"];

        // 1/4 : set Camera position
        mCamera->setPosition(camera["position"]["x"].GetDouble(), camera["position"]["y"].GetDouble(), camera["position"]["z"].GetDouble());

        // 2/4 : create renderables
        //TODO : add renderable factory
        for (SizeType i = 0; i != models.Size(); ++i)
        {
            const Value & pos = models[i]["position"];
            const Value & scale = models[i]["scale"];
            std::string type = models[i]["type"].GetString();
            Renderable* r = RenderableFactory::getByName(type);

            r->setPosition(glm::vec3(pos["x"].GetDouble(), pos["y"].GetDouble(), pos["z"].GetDouble()));
            //r->setRotation();
            r->setScale(glm::vec3(scale["x"].GetDouble(), scale["y"].GetDouble(), scale["z"].GetDouble()));

            addRenderable(r);
        }

    }
}