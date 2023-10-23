
// ______________________________________________________________________

#include <Nero/Graphics/RenderData.hpp>

// ______________________________________________________________________

namespace Nero
{
    RenderData::RenderData()
        : VertexData({}), IndexData({}), Primitive(PrimitiveType::Triangles)
    {
    }

    RenderData::RenderData(const std::vector<Vertex> &p_VertexData, const PrimitiveType &p_Primitive)
        : VertexData(p_VertexData), IndexData({}), Primitive(p_Primitive)
    {
    }

    RenderData::RenderData(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData, const PrimitiveType &p_Primitive)
        : VertexData(p_VertexData), IndexData(p_IndexData), Primitive(p_Primitive)
    {
    }

    const RenderData &RenderData::operator= (const RenderData &p_RenderData)
    {
        this->Primitive     = p_RenderData.Primitive;
        this->VertexData    = p_RenderData.VertexData;
        this->IndexData     = p_RenderData.IndexData;
        
        return *this;
    }
}

// ______________________________________________________________________
