
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/Color.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API Vertex
    {
    public:
        glm::vec4 a_Position    = glm::vec4(0.0f);  // vertex position
        glm::vec4 a_Color       = glm::vec4(0.0f);  // vertex color
        glm::vec2 a_Coord       = glm::vec2(0.0f);  // vertex texture coordinates

        Vertex();
        Vertex(const glm::vec4 &p_Position);

        Vertex(const glm::vec4 &a_Position, const glm::vec2 &p_Coord);
        Vertex(const glm::vec4 &p_Position, const glm::vec4 &p_Color);
        Vertex(const glm::vec4 &p_Position, const Color     &p_Color);

        Vertex(const glm::vec4 &p_Position, const glm::vec4 &p_Color, const glm::vec2 &p_Coord);
        Vertex(const glm::vec4 &p_Position, const Color     &p_Color, const glm::vec2 &p_Coord);
    };
}

// ______________________________________________________________________
