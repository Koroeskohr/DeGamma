#include <FreeflyCamera.hpp>

namespace glimac{
    FreeflyCamera::FreeflyCamera() :
        m_fPhi(glm::pi<float>()),
        m_fTheta(0)
    {
        computeDirectionVectors();
    }

    void FreeflyCamera::computeDirectionVectors()
    {
        const float PI = glm::pi<float>();
        float theta = m_fTheta;
        float phi = m_fPhi;
        m_FrontVector = glm::vec3(glm::cos(theta)*glm::sin(phi),
                                  glm::sin(theta),
                                  glm::cos(theta)*glm::cos(phi));

        m_LeftVector = glm::vec3(glm::sin(phi + PI/2),
                                 0,
                                 glm::cos(phi + PI/2));

        m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
    }


    void FreeflyCamera::moveLeft(float t) {
        m_Position += t*m_LeftVector;
    }

    void FreeflyCamera::moveFront(float t) {
        m_Position += t*m_FrontVector;
    }

    void FreeflyCamera::rotateLeft(float degrees) {
        m_fPhi += glm::radians(degrees);
        computeDirectionVectors();
    }

    void FreeflyCamera::rotateUp(float degrees) {
        m_fTheta += glm::radians(degrees);
        computeDirectionVectors();
    }

    glm::mat4 FreeflyCamera::getViewMatrix() const {
        return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);

    }
}