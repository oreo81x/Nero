
// ______________________________________________________________________

#include <Nero/Graphics/Extension.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    glm::mat4 CreateModelMatrix(const glm::vec3 &p_Origin, const glm::vec3 &p_Scale, const glm::vec3 &p_Rotation)
    {
        return  glm::translate(glm::mat4(1.0f), p_Origin)   *
                glm::mat4_cast(glm::quat(p_Rotation))       *
                glm::scale(glm::mat4(1.0f), p_Scale);
    }

    glm::mat4 CreateViewMatrix(const glm::vec3 &p_Origin, const glm::vec3 &p_Scale, const glm::vec3 &p_Rotation)
    {
        return glm::inverse(CreateModelMatrix(p_Origin, p_Scale, p_Rotation));
    }

    glm::mat4 CreatePerspectiveProjectionMatrix(const float &p_FieldOfView, const float &p_AspectRation, const float &p_NearPlane, const float &p_FarPlane)
    {
        return glm::perspectiveRH(p_FieldOfView, p_AspectRation, p_NearPlane, p_FarPlane);
    }

    glm::mat4 CreateOrthographicProjectionMatrix(const float &p_Width, const float &p_Height, const float &p_NearPlane, const float &p_FarPlane)
    {
        return glm::orthoRH(0.0f, p_Width, 0.0f, p_Height, p_NearPlane, p_FarPlane);
    }

    // ______________________________________________________________________

    RenderData CreateSurface(const glm::mat4 &p_Transform, const Color &p_Color)
    {
        std::vector<Vertex> vertexData =
        {
            Vertex(p_Transform * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), p_Color, glm::vec2(0.0f, 0.0f)),
            Vertex(p_Transform * glm::vec4( 0.5f,  0.5f, 0.0f, 1.0f), p_Color, glm::vec2(1.0f, 1.0f)),
            Vertex(p_Transform * glm::vec4( 0.5f, -0.5f, 0.0f, 1.0f), p_Color, glm::vec2(1.0f, 0.0f)),
            Vertex(p_Transform * glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f), p_Color, glm::vec2(0.0f, 1.0f))
        };

        std::vector<unsigned int> indexData =
        {
            0, 1, 2,
            0, 1, 3
        };

        return RenderData(vertexData, indexData);
    }

    RenderData CreateTriangle(const glm::mat4 &p_Transform, const Color &p_Color)
    {
        std::vector<Vertex> vertexData =
        {
            Vertex(p_Transform * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), p_Color, glm::vec2(0.0f, 0.0f)),
            Vertex(p_Transform * glm::vec4( 0.5f, -0.5f, 0.0f, 1.0f), p_Color, glm::vec2(1.0f, 0.0f)),
            Vertex(p_Transform * glm::vec4( 0.0f,  0.5f, 0.0f, 1.0f), p_Color, glm::vec2(0.5f, 1.0f))
        };

        std::vector<unsigned int> indexData =
        {
            0, 1, 2
        };

        return RenderData(vertexData, indexData);
    }

    RenderData CreateCube(const glm::mat4 &p_Transform, const Color &p_Color)
    {
        std::vector<Vertex> vertexData =
        {

        };

        std::vector<unsigned int> indexData =
        {

        };

        RenderData cubeFace1 = CreateSurface(p_Transform * CreateModelMatrix(glm::vec3(0.0f, 0.0f,  0.5f), glm::vec3(1.0f), glm::radians(glm::vec3(0.0f,   0.0f, 0.0f))), p_Color); // cube face
        RenderData cubeFace2 = CreateSurface(p_Transform * CreateModelMatrix(glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(1.0f), glm::radians(glm::vec3(0.0f, 180.0f, 0.0f))), p_Color); // cube back

        RenderData cubeFace3 = CreateSurface(p_Transform * CreateModelMatrix(glm::vec3(0.0f,  0.5f, 0.0f), glm::vec3(1.0f), glm::radians(glm::vec3(-90.0f, 0.0f, 0.0f))), p_Color); // cube up
        RenderData cubeFace4 = CreateSurface(p_Transform * CreateModelMatrix(glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(1.0f), glm::radians(glm::vec3( 90.0f, 0.0f, 0.0f))), p_Color); // cube bottom
        
        RenderData cubeFace5 = CreateSurface(p_Transform * CreateModelMatrix(glm::vec3( 0.5f, 0.0f, 0.0f), glm::vec3(1.0f), glm::radians(glm::vec3(0.0f, -90.0f, 0.0f))), p_Color); // cube right
        RenderData cubeFace6 = CreateSurface(p_Transform * CreateModelMatrix(glm::vec3(-0.5f, 0.0f, 0.0f), glm::vec3(1.0f), glm::radians(glm::vec3(0.0f,  90.0f, 0.0f))), p_Color); // cube left

        vertexData.insert(vertexData.end(), cubeFace1.VertexData.begin(), cubeFace1.VertexData.end());
        vertexData.insert(vertexData.end(), cubeFace2.VertexData.begin(), cubeFace2.VertexData.end());

        vertexData.insert(vertexData.end(), cubeFace3.VertexData.begin(), cubeFace3.VertexData.end());
        vertexData.insert(vertexData.end(), cubeFace4.VertexData.begin(), cubeFace4.VertexData.end());

        vertexData.insert(vertexData.end(), cubeFace5.VertexData.begin(), cubeFace5.VertexData.end());
        vertexData.insert(vertexData.end(), cubeFace6.VertexData.begin(), cubeFace6.VertexData.end());

        indexData.insert(indexData.end(), cubeFace1.IndexData.begin(), cubeFace1.IndexData.end());
        indexData.insert(indexData.end(), cubeFace2.IndexData.begin(), cubeFace2.IndexData.end());

        indexData.insert(indexData.end(), cubeFace3.IndexData.begin(), cubeFace3.IndexData.end());
        indexData.insert(indexData.end(), cubeFace4.IndexData.begin(), cubeFace4.IndexData.end());

        indexData.insert(indexData.end(), cubeFace5.IndexData.begin(), cubeFace5.IndexData.end());
        indexData.insert(indexData.end(), cubeFace6.IndexData.begin(), cubeFace6.IndexData.end());

        unsigned int scaler = 0;

        for (unsigned long long index = 0; index < indexData.size(); ++index)
        {
            if (index > 0 && (index % 6) == 0)
            {
                ++scaler;
            }

            indexData[index] += 4 * scaler;
        }

        return RenderData(vertexData, indexData);
    }

    RenderData CreatePyramid(const glm::mat4 &p_Transform, const Color &p_Color)
    {
        std::vector<Vertex> vertexData =
        {

        };

        std::vector<unsigned int> indexData =
        {

        };

        return RenderData(vertexData, indexData);
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
