
// ______________________________________________________________________

#include <Nero/Graphics/PrimitiveType.hpp>
#include <Nero/OpenGL.hpp>

// ______________________________________________________________________

namespace Nero
{
    unsigned int InGLEnum(const PrimitiveType &p_Primitive)
    {
        return  (p_Primitive == PrimitiveType::Points)          ? GL_POINTS         :
                (p_Primitive == PrimitiveType::Lines)           ? GL_LINES          :
                (p_Primitive == PrimitiveType::LineStrip)       ? GL_LINE_STRIP     :
                (p_Primitive == PrimitiveType::LineLoop)        ? GL_LINE_LOOP      :
                (p_Primitive == PrimitiveType::Triangles)       ? GL_TRIANGLES      :
                (p_Primitive == PrimitiveType::TriangleStrip)   ? GL_TRIANGLE_STRIP :
                (p_Primitive == PrimitiveType::TriangleFan)     ? GL_TRIANGLE_FAN   : Error("Invalid PrimitiveType Enum Value");
    }
}

// ______________________________________________________________________
