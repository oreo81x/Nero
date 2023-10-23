
// ______________________________________________________________________

#include <Nero/Graphics/Stencil.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    Stencil::Stencil(const unsigned char &p_Value)
    {
        StencilValue = p_Value;
    }

    Stencil::~Stencil()
    {
        StencilValue = 0;
    }

    // ______________________________________________________________________

    const Stencil &Stencil::operator= (const Stencil &p_Right)
    {
        StencilValue = p_Right.StencilValue;

        return *this;
    }

    bool Stencil::operator== (const Stencil &p_Right)
    {
        return StencilValue == p_Right.StencilValue;
    }

    bool Stencil::operator!= (const Stencil &p_Right)
    {
        return !operator== (p_Right);
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
