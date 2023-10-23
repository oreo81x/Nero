
// ______________________________________________________________________

#include <Nero/Graphics/Actor.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    Actor::~Actor()
    {

    }

    // ______________________________________________________________________

    glm::vec3 Actor::GetFront() const
    {
        return -glm::normalize(glm::vec3(glm::inverse(GetMatrix())[2]));
    }

    glm::vec3 Actor::GetRight() const
    {
        return glm::normalize(glm::cross(GetFront(), glm::vec3(0.0f, 1.0f, 0.0f)));
    }

    glm::vec3 Actor::GetUp() const
    {
        return glm::normalize(glm::cross(GetRight(), GetFront()));
    }

    // ______________________________________________________________________

    glm::mat4 Actor::GetMatrix() const
    {
        return glm::scale(glm::mat4(1.0f), m_Scale) * glm::mat4_cast(m_Rotation) * glm::translate(glm::mat4(1.0f), m_Origin);
    }

    glm::vec3 Actor::GetOrigin() const
    {
        return m_Origin;
    }

    glm::vec3 Actor::GetRotation() const
    {
        return glm::eulerAngles(m_Rotation);
    }

    glm::quat Actor::GetRotationQuat() const
    {
        return m_Rotation;
    }

    glm::vec3 Actor::GetScale() const
    {
        return m_Scale;
    }

    // ______________________________________________________________________

    void Actor::LetOrigin(const glm::vec3 &p_Origin)
    {
        m_Origin = p_Origin;
    }

    void Actor::LetRotation(const glm::vec3 &p_Rotation)
    {
        m_Rotation  = glm::quat(glm::vec3(0.0f));
        m_Rotation  = glm::angleAxis(p_Rotation.z, GetFront ());
        m_Rotation *= glm::angleAxis(p_Rotation.y, GetUp    ());
        m_Rotation *= glm::angleAxis(p_Rotation.x, GetRight ());
        m_Rotation  = glm::normalize(m_Rotation);
    }

    void Actor::LetRotationQuat(const glm::quat &p_Rotation)
    {
        m_Rotation = glm::normalize(p_Rotation);
    }

    void Actor::LetScale(const glm::vec3 &p_Scale)
    {
        m_Scale = p_Scale;
    }

    // ______________________________________________________________________

    void Actor::Move(const glm::vec3 &p_Offset)
    {
        LetOrigin(m_Origin + p_Offset);
    }

    void Actor::Rotate(const glm::vec3 &p_Rotation)
    {
        LetRotation(glm::eulerAngles(m_Rotation) + p_Rotation);
    }

    void Actor::Scale(const glm::vec3 &p_Scale)
    {
        LetScale(m_Scale + p_Scale);
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
