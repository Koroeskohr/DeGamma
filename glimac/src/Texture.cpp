//
// Created by koro on 16/12/15.
//

#include "Texture.hpp"


namespace glimac {
    Texture::Texture(const std::string& name, std::unique_ptr<Image> const & texImage,
                     glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular,
                     GLfloat shininess)
        : mMaterialName(name),
          mDiffuseColor(glm::vec4(diffuse, 1)),
          mAmbientColor(glm::vec4(ambient, 1)),
          mSpecularColor(glm::vec4(specular, 1)),
          mShininess(shininess),
          mTexImageWidth(texImage->getWidth()),
          mTexImageHeight(texImage->getHeight()),
          hasTexture(true)

    {
        std::cout << "Creating texture with name " << name << std::endl;
        init(texImage);
    }

    Texture::Texture(const std::string& name,
                     glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular,
                     GLfloat shininess)
            : mMaterialName(name),
              mDiffuseColor(glm::vec4(diffuse, 1)),
              mAmbientColor(glm::vec4(ambient, 1)),
              mSpecularColor(glm::vec4(specular, 1)),
              mShininess(shininess),
              hasTexture(false)
    {
        std::cout << "Creating texture (color only) with name " << name << std::endl;
    }

    Texture::~Texture() {
        std::cout << "Texture removed : " << mMaterialName << " at id " << mGlTexture << std::endl;
        glDeleteTextures(1, &mGlTexture);
    }

    void Texture::init (std::unique_ptr<Image> const & texImage) {
        glGenTextures(1, &mGlTexture);
        glBindTexture(GL_TEXTURE_2D, mGlTexture);

        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGBA,
                     texImage->getWidth(),
                     texImage->getHeight(),
                     0,
                     GL_RGBA,
                     GL_FLOAT,
                     texImage->getPixels());

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glBindTexture(GL_TEXTURE_2D, 0);
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
