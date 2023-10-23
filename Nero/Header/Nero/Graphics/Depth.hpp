
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API Depth
    {
    public:
        float DepthValue = 0.0f;

    public:
         Depth(const float &p_Value = 1.0f);
        ~Depth();

        const Depth &operator=  (const Depth &p_Right);
        bool         operator== (const Depth &p_Right);
        bool         operator!= (const Depth &p_Right);
    };
}

// ______________________________________________________________________
