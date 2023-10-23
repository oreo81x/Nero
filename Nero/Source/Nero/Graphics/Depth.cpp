
// ______________________________________________________________________

#include <Nero/Graphics/Depth.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________
    
    Depth::Depth(const float &p_Value)
    {
        DepthValue = p_Value;
    }

    Depth::~Depth()
    {
        DepthValue = 0.0f;
    }

    // ______________________________________________________________________

    const Depth &Depth::operator= (const Depth &p_Right)
    {
        DepthValue = p_Right.DepthValue;

        return *this;
    }

    bool Depth::operator== (const Depth &p_Right)
    {
        return DepthValue == p_Right.DepthValue;
    }

    bool Depth::operator!= (const Depth &p_Right)
    {
        return !operator== (p_Right);
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
