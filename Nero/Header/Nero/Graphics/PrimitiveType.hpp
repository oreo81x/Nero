
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>

// ______________________________________________________________________

namespace Nero
{
    enum class PrimitiveType : unsigned char
    {
        Points          = 0,
        Lines           = 1,
        LineStrip       = 2,
        LineLoop        = 3,
        Triangles       = 4,
        TriangleStrip   = 5,
        TriangleFan     = 6
    };

    unsigned int InGLEnum(const PrimitiveType &p_Primitive);
}

// ______________________________________________________________________
