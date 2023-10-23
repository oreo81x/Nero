
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/Actor.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API Camera : public Actor
    {
    public:
        glm::vec3 GetFront  () const override;
        glm::vec3 GetRight  () const override;
        glm::vec3 GetUp     () const override;

        glm::mat4 GetViewMatrix         () const;
        glm::mat4 GetProjectionMatrix   () const;
        
        glm::mat4 GetMatrix         () const override;
        glm::vec3 GetOrigin         () const override;
        glm::vec3 GetRotation       () const override;
        glm::quat GetRotationQuat   () const override;
        glm::vec3 GetScale          () const override;

        float GetFieldOfView    () const;
        float GetWidth          () const;
        float GetHeight         () const;
        float GetNearPlane      () const;
        float GetFarPlane       () const;

        void LetOrigin          (const glm::vec3 &p_Origin)     override;
        void LetRotation        (const glm::vec3 &p_Rotation)   override;
        void LetRotationQuat    (const glm::quat &p_Rotation)   override;
        void LetScale           (const glm::vec3 &p_Scale)      override;

        void LetFieldOfView     (const float &p_FieldOfView);
        void LetWidth           (const float &p_Width);
        void LetHeight          (const float &p_Height);
        void LetNearPlane       (const float &p_NearPlane);
        void LetFarPlane        (const float &p_FarPlane);

        void Move   (const glm::vec3 &p_Offset)     override;
        void Rotate (const glm::vec3 &p_Rotation)   override;
        void Scale  (const glm::vec3 &p_Scale)      override;

    private:
        glm::vec3 m_Origin      = glm::vec3(0.0f, 0.0f,  0.0f);
        glm::vec3 m_Rotation    = glm::vec3(0.0f, 0.0f,  0.0f);
        glm::vec3 m_Scale       = glm::vec3(1.0f, 1.0f,  1.0f);
        glm::quat m_QRotation   = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));

        float m_FieldOfView = 45.0f;

        float m_Width   = 0.0f;
        float m_Height  = 0.0f;

        float m_NearPlane   = 0.1f;
        float m_FarPlane    = 100.0f;
    };
}

// ______________________________________________________________________
