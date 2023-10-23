
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API Stencil
    {
    public:
        unsigned char StencilValue = 0;

    public:
         Stencil(const unsigned char &p_Value = 0);
        ~Stencil();

        const Stencil   &operator=  (const Stencil &p_Right);
        bool             operator== (const Stencil &p_Right);
        bool             operator!= (const Stencil &p_Right);
    };
}

// ______________________________________________________________________
