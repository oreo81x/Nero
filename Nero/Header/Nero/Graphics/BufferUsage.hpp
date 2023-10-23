
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>

// ______________________________________________________________________

namespace Nero
{
    enum class BufferUsage : unsigned char
    {
        Static  = 0,
        Dynamic = 1,
        Stream  = 2
    };

    unsigned int InGLEnum(const BufferUsage &p_Usage);
}

// ______________________________________________________________________
