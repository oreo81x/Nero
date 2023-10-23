
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/Vertex.hpp>
#include <Nero/Graphics/PrimitiveType.hpp>

// ______________________________________________________________________

namespace Nero
{
    struct NERO_API RenderData
    {
        RenderData();
        RenderData(const std::vector<Vertex> &p_VertexData,                                                 const PrimitiveType &p_Primitive = PrimitiveType::Triangles);
        RenderData(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData,   const PrimitiveType &p_Primitive = PrimitiveType::Triangles);

        PrimitiveType               Primitive   = PrimitiveType::Triangles;
        std::vector<Vertex>         VertexData  = {};
        std::vector<unsigned int>   IndexData   = {};
        
        const RenderData &operator= (const RenderData &p_RenderData);
    };
}

// ______________________________________________________________________
