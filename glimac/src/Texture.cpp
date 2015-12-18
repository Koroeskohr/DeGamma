//
// Created by koro on 16/12/15.
//

#include "Texture.hpp"


namespace glimac {
    Texture::Texture(const std::string& name,
                     glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular,
                     GLfloat shininess)
    {

    }

    Texture::~Texture() {
        glDeleteTextures(1, &mGlTexture);
    }

    std::string Texture::getName () const {
        return mMaterialName;
    }
    glm::vec4 Texture::getDiffuseColor () const {
        return mDiffuseColor;
    }
    glm::vec4 Texture::getAmbientColor () const {
        return mAmbientColor;
    }
    glm::vec4 Texture::getSpecularColor () const {
        return mSpecularColor;
    }
    GLfloat Texture::getShininess () const {
        return mShininess;
    }
    GLuint Texture::getGlTexture () const {
        return mGlTexture;
    }

    void Texture::setSpecularColor (glm::vec4 specular) {
        mSpecularColor = specular;
    }
    void Texture::setAmbientColor (glm::vec4 ambient) {
        mAmbientColor = ambient;
    }
    void Texture::setDiffuseColor (glm::vec4 diffuse) {
        mDiffuseColor = diffuse;
    }
    void Texture::setShininess (GLfloat shininess) {
        mShininess = shininess;
    }
}
