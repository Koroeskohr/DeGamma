//
// Created by Lucas Hörand on 10/01/2016.
//

#ifndef DEGAMMA_SKYBOX_H
#define DEGAMMA_SKYBOX_H


#include "common.hpp"
#include "Image.hpp"
#include "Program.hpp"
#include <vector>


namespace glimac{
    class Skybox {

        public:

        Skybox();
        ~Skybox();
        void draw(glm::mat4 projection, glm::mat4 view);

        private:
            Program * mProgram;
            GLfloat mVertices[108];
            std::vector<const GLchar*> mFaces;

            GLuint mVAO;
            GLuint mTexture;

            GLuint loadCubemap(std::vector<const GLchar*> faces);





    };
}



#endif //DEGAMMA_SKYBOX_H
