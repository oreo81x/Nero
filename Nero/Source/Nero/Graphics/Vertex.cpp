
// ______________________________________________________________________

#include <Nero/Graphics/Vertex.hpp>

// ______________________________________________________________________

namespace Nero
{
    Vertex::Vertex()
    {
        a_Position  = glm::vec4(0.0f);
        a_Color     = glm::vec4(0.0f);
        a_Coord     = glm::vec2(0.0f);
    }

    Vertex::Vertex(const glm::vec4 &p_Position)
    {
        a_Position  = p_Position;
        a_Color     = glm::vec4(0.0f);
        a_Coord     = glm::vec2(0.0f);
    }

    Vertex::Vertex(const glm::vec4 &p_Position, const glm::vec2 &p_Coord)
    {
        a_Position  = p_Position;
        a_Color     = glm::vec4(0.0f);
        a_Coord     = p_Coord;
    }

    Vertex::Vertex(const glm::vec4 &p_Position, const glm::vec4 &p_Color)
    {
        a_Position  = p_Position;
        a_Color     = p_Color;
        a_Coord     = glm::vec2(0.0f);
    }

    Vertex::Vertex(const glm::vec4 &p_Position, const Color &p_Color)
    {
        a_Position  = p_Position;
        a_Color     = glm::vec4(p_Color.InUnit().R, p_Color.InUnit().G, p_Color.InUnit().B, p_Color.InUnit().A);
        a_Coord     = glm::vec2(0.0f);
    }

    Vertex::Vertex(const glm::vec4 &p_Position, const glm::vec4 &p_Color, const glm::vec2 &p_Coord)
    {
        a_Position  = p_Position;
        a_Color     = p_Color;
        a_Coord     = p_Coord;
    }

    Vertex::Vertex(const glm::vec4 &p_Position, const Color &p_Color, const glm::vec2 &p_Coord)
    {
        a_Position  = p_Position;
        a_Color     = glm::vec4(p_Color.InUnit().R, p_Color.InUnit().G, p_Color.InUnit().B, p_Color.InUnit().A);
        a_Coord     = p_Coord;
    }
}

// ______________________________________________________________________
