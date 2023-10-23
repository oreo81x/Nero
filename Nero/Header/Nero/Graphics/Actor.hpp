
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API Actor
    {
    public:
        virtual ~Actor() = 0;

        virtual glm::vec3 GetFront  () const;
        virtual glm::vec3 GetRight  () const;
        virtual glm::vec3 GetUp     () const;

        virtual glm::mat4 GetMatrix         () const;
        virtual glm::vec3 GetOrigin         () const;
        virtual glm::vec3 GetRotation       () const;
        virtual glm::quat GetRotationQuat   () const;
        virtual glm::vec3 GetScale          () const;

        virtual void LetOrigin          (const glm::vec3 &p_Origin);
        virtual void LetRotation        (const glm::vec3 &p_Rotation);
        virtual void LetRotationQuat    (const glm::quat &p_Rotation);
        virtual void LetScale           (const glm::vec3 &p_Scale);

        virtual void Move   (const glm::vec3 &p_Offset);
        virtual void Rotate (const glm::vec3 &p_Rotation);
        virtual void Scale  (const glm::vec3 &p_Scale);

    protected:
        glm::vec3 m_Origin      = glm::vec3(0.0f);
        glm::quat m_Rotation    = glm::quat(glm::vec3(0.0f));
        glm::vec3 m_Scale       = glm::vec3(1.0f);
    };
}

// ______________________________________________________________________
