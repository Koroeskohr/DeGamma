//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_TEXTURE_HPP
#define DEGAMMA_TEXTURE_HPP

#include <assimp/material.h>
#include "common.hpp"
#include "Image.hpp"
#include <memory>
#include <iostream>

namespace glimac {

class Texture {
public:
    Texture (const std::string &name, std::unique_ptr<Image> const & texImage, glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular,
                 GLfloat shininess);
    Texture();
    ~Texture();

    void init(std::unique_ptr<Image> const & texImage);

    std::string getName() const;
    GLuint getGlTexture() const;
    glm::vec4 getSpecularColor() const;
    glm::vec4 getAmbientColor() const;
    glm::vec4 getDiffuseColor() const;
    GLfloat getShininess() const;

    void setSpecularColor(glm::vec4 specular);
    void setAmbientColor(glm::vec4 ambient);
    void setDiffuseColor(glm::vec4 diffuse);
    void setShininess(GLfloat shininess);

private:
    std::string mMaterialName;
    GLuint mGlTexture;
    GLfloat mTexImageWidth;
    GLfloat mTexImageHeight;

    glm::vec4 mDiffuseColor;
    glm::vec4 mAmbientColor;
    glm::vec4 mSpecularColor;
    GLfloat mShininess;
};

}




#endif //DEGAMMA_TEXTURE_HPP
