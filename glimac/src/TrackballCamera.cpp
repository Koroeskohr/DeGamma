#include "TrackballCamera.hpp"

namespace glimac{

    TrackballCamera::TrackballCamera(float fDistance, float fAngleX, float fAngleY):
            m_fDistance(fDistance), m_fAngleX(fAngleX), m_fAngleY(fAngleY)
    {
    }

    void TrackballCamera::moveFront(float delta)
    {
        m_fDistance += delta;
    }
    void TrackballCamera::rotateLeft(float degrees)
    {
        m_fAngleY += degrees;
    }
    void TrackballCamera::rotateUp(float degrees)
    {
        m_fAngleX += degrees;
    }


    glm::mat4 TrackballCamera::getViewMatrix() const {
        glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -m_fDistance));

        viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(0.0f, 1.0f, 0.0f));
        viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(1.0f, 0.0f, 0.0f));

        return viewMatrix;
    }
}

