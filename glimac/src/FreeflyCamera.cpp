#include <FreeflyCamera.hpp>


namespace glimac{
    FreeflyCamera::FreeflyCamera(glm::mat4 projection) :
        m_fPhi(glm::pi<float>()),
        m_fTheta(0),
        mProjection(projection)
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

    void FreeflyCamera::moveUp (float t) {
        m_Position += t * glm::vec3(0,1,0);
    }

    void FreeflyCamera::rotateLeft(float degrees) {
        m_fPhi += glm::radians(degrees);
        computeDirectionVectors();
    }

    void FreeflyCamera::rotateUp(float degrees) {
        m_fTheta += glm::radians(degrees);
        m_fTheta = std::max<float>(glm::radians(-90.0f), std::min<float>(m_fTheta, glm::radians(90.0f)));
        computeDirectionVectors();
    }

    glm::mat4 FreeflyCamera::getViewMatrix() const {
        return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
    }

    glm::mat4 FreeflyCamera::getProjectionMatrix() const {
        return mProjection;
    }


    FreeflyCamera::~FreeflyCamera () {
        std::cout << "Free fly camera deleted" << std::endl;
    }

    void FreeflyCamera::setPosition (glm::vec3 &pos) {
        m_Position = pos;
    }

    void FreeflyCamera::setPosition (float x, float y, float z) {
        m_Position = glm::vec3(x,y,z);
    }


}