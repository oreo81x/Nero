
// ______________________________________________________________________

#include <Nero/Graphics/Camera.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    glm::vec3 Camera::GetFront() const
    {
        return glm::normalize(glm::vec3(glm::inverse(GetViewMatrix())[2]));
    }

    glm::vec3 Camera::GetRight() const
    {
        return glm::normalize(glm::cross(GetFront(), glm::vec3(0.0f, 1.0f, 0.0f)));
    }

    glm::vec3 Camera::GetUp() const
    {
        return -glm::normalize(glm::cross(GetRight(), GetFront()));
    }

    // ______________________________________________________________________

    glm::mat4 Camera::GetViewMatrix() const
    {
        return glm::scale(glm::mat4(1.0f), m_Scale) * glm::mat4_cast(glm::normalize(m_QRotation)) * glm::translate(glm::mat4(1.0f), -m_Origin);
    }

    glm::mat4 Camera::GetProjectionMatrix() const
    {
        return glm::perspective(glm::radians(m_FieldOfView), m_Width / m_Height, m_NearPlane, m_FarPlane);
    }

    // ______________________________________________________________________

    glm::mat4 Camera::GetMatrix() const
    {
        return GetProjectionMatrix() * GetViewMatrix();
    }

    glm::vec3 Camera::GetOrigin() const
    {
        return m_Origin;
    }

    glm::vec3 Camera::GetRotation() const
    {
        return m_Rotation;
    }

    glm::vec3 Camera::GetScale() const
    {
        return m_Scale;
    }

    // ______________________________________________________________________

    float Camera::GetFieldOfView() const
    {
        return m_FieldOfView;
    }

    float Camera::GetWidth() const
    {
        return m_Width;
    }

    float Camera::GetHeight() const
    {
        return m_Height;
    }

    float Camera::GetNearPlane() const
    {
        return m_NearPlane;
    }

    float Camera::GetFarPlane() const
    {
        return m_FarPlane;
    }

    // ______________________________________________________________________

    void Camera::LetOrigin(const glm::vec3 &p_Origin)
    {
        m_Origin = p_Origin;
    }

    void Camera::LetRotation(const glm::vec3 &p_Rotation)
    {
        m_Rotation = p_Rotation;

        m_QRotation  = glm::angleAxis(glm::radians(-m_Rotation.z), glm::vec3(0.0f, 0.0f, -1.0f));
        m_QRotation *= glm::angleAxis(glm::radians(-m_Rotation.y), GetUp    ());
        m_QRotation *= glm::angleAxis(glm::radians( m_Rotation.x), GetRight ());
    }

    void Camera::LetScale(const glm::vec3 &p_Scale)
    {
        m_Scale = p_Scale;
    }

    // ______________________________________________________________________

    void Camera::LetFieldOfView(const float &p_FieldOfView)
    {
        m_FieldOfView = p_FieldOfView;
    }

    void Camera::LetWidth(const float &p_Width)
    {
        m_Width = p_Width;
    }

    void Camera::LetHeight(const float &p_Height)
    {
        m_Height = p_Height;
    }

    void Camera::LetNearPlane(const float &p_NearPlane)
    {
        m_NearPlane = p_NearPlane;
    }

    void Camera::LetFarPlane(const float &p_FarPlane)
    {
        m_FarPlane = p_FarPlane;
    }

    // ______________________________________________________________________

    void Camera::Move(const glm::vec3 &p_Offset)
    {
        m_Origin += -p_Offset;
    }

    void Camera::Rotate(const glm::vec3 &p_Rotation)
    {
        m_Rotation += p_Rotation;
        LetRotation(m_Rotation);
    }

    void Camera::Scale(const glm::vec3 &p_Scale)
    {
        m_Scale += p_Scale;
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
