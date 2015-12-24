//
// Created by koro on 16/12/15.
//

#include "Engine.hpp"
#include "Program.hpp"
#include "FreeflyCamera.hpp"

struct myProgram{

    glimac::Program mProgram;

    GLint model;
    GLint view;
    GLint projection;


    myProgram():
            mProgram(glimac::loadProgram("/Users/Luhof/Documents/IMAC2/projetogl/DeGamma/shaders/3D.vs.glsl",
                                         "/Users/Luhof/Documents/IMAC2/projetogl/DeGamma/shaders/3D.fs.glsl")){
        model = glGetUniformLocation(mProgram.getGLId(), "model");
        view = glGetUniformLocation(mProgram.getGLId(), "view");
        projection = glGetUniformLocation(mProgram.getGLId(), "projection");

    }

};





Engine * Engine::mInstance = nullptr;

Engine* Engine::getInstance() {
    if (mInstance == nullptr)
        mInstance = new Engine;

    return mInstance;
}

Engine::Engine()
        : mWindowManager(new SDLWindowManager(640,480,"YOloGL")),
          mResourceManager()
{
    glewExperimental = GL_TRUE;

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        throw std::runtime_error("Error initializing glew");
    }
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);

    //createManagers();



    //TODO : start timers
}

Engine::~Engine(){
    //TODO
}

void Engine::createManagers () {
    mResourceManager = std::unique_ptr<ResourceManager>(ResourceManager::getInstance());
    mWindowManager = std::unique_ptr<SDLWindowManager>(new SDLWindowManager(1280,720, "DeGamma"));
}

void Engine::loop () {




    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);



    myProgram program;
    program.mProgram.use();


    /*static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };

    GLuint vertexbuffer;
    GLuint vao;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);



    // 1rst attribute buffer : vertices
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);
    glEnableVertexAttribArray(5);

    glVertexAttribPointer(
            5,                  // attribute 5. Because other ones are used lolmdr
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);*/

    AirboatModel myLittleAirboat;

    FreeflyCamera myCamera;


    //RED TRIANGLE STUFF

    GLfloat vertices[] = {
            -0.5f, -0.5f, -1.0f,
            0.5f, -0.5f, -1.0f,
            0.0f,  0.5f, -1.0f
    };

    GLuint VBO;
    GLuint VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBindVertexArray(VAO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(5);

    glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);






    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while (mWindowManager->pollEvent(e)) {
            if (e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 projection = glm::perspective(glm::radians(40.0f), (float)640.0f/(float)480.0f, 0.1f, 100.0f);
        glm::mat4 view = myCamera.getViewMatrix();
        glUniformMatrix4fv(program.projection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(program.view, 1, GL_FALSE, glm::value_ptr(view));
        glm::mat4 model(1);

        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
        glUniformMatrix4fv(program.model, 1, GL_FALSE, glm::value_ptr(model));

        //it works with 1 red triangle
        //it should work with 10000 triangle HEH ???
        //NOTA BENE (à ordure) : projection matrix makes the triangle disappear ?
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

         myLittleAirboat.draw();




        mWindowManager->swapBuffers();


    }

}
