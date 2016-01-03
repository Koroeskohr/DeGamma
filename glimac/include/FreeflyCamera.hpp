#pragma once

#include "common.hpp"
#include <iostream>

namespace glimac{

class FreeflyCamera{
private:
    glm::vec3 m_Position;
    float m_fPhi, m_fTheta;
    glm::vec3 m_FrontVector;
    glm::vec3 m_LeftVector;
    glm::vec3 m_UpVector;
    glm::mat4 mProjection;

    void computeDirectionVectors();

public:
    FreeflyCamera(glm::mat4 projection);
    ~FreeflyCamera ();
    void setPosition(glm::vec3 & pos);
    void setPosition(float x, float y, float z);
    void moveLeft(float t);
    void moveFront(float t);
    void rotateLeft(float degrees);
    void rotateUp(float degrees);
    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix() const;


};


}