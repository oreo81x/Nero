
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/Color.hpp>
#include <Nero/Graphics/Vertex.hpp>
#include <Nero/Graphics/PrimitiveType.hpp>
#include <Nero/Graphics/RenderData.hpp>

// ______________________________________________________________________

namespace Nero
{
    glm::mat4 NERO_API CreateModelMatrix                    (const glm::vec3 &p_Origin, const glm::vec3 &p_Scale, const glm::vec3 &p_Rotation);
    glm::mat4 NERO_API CreateViewMatrix                     (const glm::vec3 &p_Origin, const glm::vec3 &p_Scale, const glm::vec3 &p_Rotation);
    glm::mat4 NERO_API CreatePerspectiveProjectionMatrix    (const float &p_FieldOfView,    const float &p_AspectRation,    const float &p_NearPlane, const float &p_FarPlane);
    glm::mat4 NERO_API CreateOrthographicProjectionMatrix   (const float &p_Width,          const float &p_Height,          const float &p_NearPlane, const float &p_FarPlane);

    RenderData NERO_API CreateSurface   (const glm::mat4 &p_Transform, const Color &p_Color);
    RenderData NERO_API CreateTriangle  (const glm::mat4 &p_Transform, const Color &p_Color);

    RenderData NERO_API CreateCube      (const glm::mat4 &p_Transform, const Color &p_Color);
    RenderData NERO_API CreatePyramid   (const glm::mat4 &p_Transform, const Color &p_Color);

    std::vector<Vertex> CreatePyramid   (const glm::mat4 &p_Model);
    std::vector<Vertex> CreateSurface   (const glm::mat4 &p_Model);
    std::vector<Vertex> CreateCube      (const glm::mat4 &p_Model);

    // ______________________________________________________________________

    static inline std::vector<Vertex> CreateSurface (const glm::mat4 &p_Model)
    {
        std::vector<Vertex> vertData =
        {
            Vertex(p_Model * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4( 0.5f,  0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
            Vertex(p_Model * glm::vec4( 0.5f, -0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),

            Vertex(p_Model * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4( 0.5f,  0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
            Vertex(p_Model * glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f))
        };

        return vertData;
    }

    static inline std::vector<Vertex> CreatePyramid(const glm::mat4 &p_Model)
    {
        std::vector<Vertex> vertData =
        {
            Vertex(p_Model * glm::vec4( 0.0f,  0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4(-0.5f, -0.5f, 0.5f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4( 0.5f, -0.5f, 0.5f, 1.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),

            Vertex(p_Model * glm::vec4( 0.0f,  0.5f,  0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4( 0.5f, -0.5f, -0.5f, 1.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),

            Vertex(p_Model * glm::vec4(0.0f,  0.5f,  0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4(0.5f, -0.5f,  0.5f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4(0.5f, -0.5f, -0.5f, 1.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),

            Vertex(p_Model * glm::vec4( 0.0f,  0.5f,  0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4(-0.5f, -0.5f,  0.5f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(p_Model * glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f))
        };

        std::vector surfaceData = CreateSurface(p_Model * CreateModelMatrix(glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::radians(glm::vec3(-90.0f, 0.0f, 0.0f))));

        vertData.insert(vertData.end(), surfaceData.begin(), surfaceData.end());

        return vertData;
    }

    static inline std::vector<Vertex> CreateCube (const glm::mat4 &p_Model)
    {
        std::vector<Vertex> vertData;

        std::vector cubeFace1 = CreateSurface(p_Model * CreateModelMatrix(-glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f),  glm::radians(glm::vec3(0.0f, 180.0f, 0.0f))));
        std::vector cubeFace2 = CreateSurface(p_Model * CreateModelMatrix( glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f),  glm::radians(glm::vec3(0.0f,   0.0f, 0.0f))));

        std::vector cubeFace3 = CreateSurface(p_Model * CreateModelMatrix(-glm::vec3(0.5f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::radians( glm::vec3(0.0f, 90.0f, 0.0f))));
        std::vector cubeFace4 = CreateSurface(p_Model * CreateModelMatrix( glm::vec3(0.5f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::radians(-glm::vec3(0.0f, 90.0f, 0.0f))));

        std::vector cubeFace5 = CreateSurface(p_Model * CreateModelMatrix(-glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::radians(-glm::vec3(90.0f, 0.0f, 0.0f))));
        std::vector cubeFace6 = CreateSurface(p_Model * CreateModelMatrix( glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::radians( glm::vec3(90.0f, 0.0f, 0.0f))));

        vertData.insert(vertData.end(), cubeFace1.begin(), cubeFace1.end());
        vertData.insert(vertData.end(), cubeFace2.begin(), cubeFace2.end());
        vertData.insert(vertData.end(), cubeFace3.begin(), cubeFace3.end());
        vertData.insert(vertData.end(), cubeFace4.begin(), cubeFace4.end());
        vertData.insert(vertData.end(), cubeFace5.begin(), cubeFace5.end());
        vertData.insert(vertData.end(), cubeFace6.begin(), cubeFace6.end());

        return vertData;
    }

}

// ______________________________________________________________________
