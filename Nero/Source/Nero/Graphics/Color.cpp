
// ______________________________________________________________________

#include <Nero/Graphics/Color.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    Color Color::White  = Color(255.0f, 255.0f, 255.0f, 255.0f);
    Color Color::Black  = Color(000.0f, 000.0f, 000.0f, 255.0f);
    Color Color::Green  = Color(025.0f, 255.0f, 025.0f, 255.0f);
    Color Color::Blue   = Color(025.0f, 025.0f, 255.0f, 255.0f);
    Color Color::Red    = Color(255.0f, 025.0f, 025.0f, 255.0f);
    Color Color::Orange = Color(255.0f, 119.0f, 051.0f, 255.0f);
    Color Color::Sky    = Color(135.0f, 206.0f, 235.0f, 000.0f);
    
    Color::Color()
        : R(0.0f), G(0.0f), B(0.0f), A(255.0f)
    {

    }

    Color::Color(const float &p_R, const float &p_G, const float &p_B, const float &p_A)
    {
        R = p_R;
        G = p_G;
        B = p_B;
        A = p_A;
    }

    Color::~Color()
    {
        R = 0.0f;
        G = 0.0f;
        B = 0.0f;
        A = 0.0f;
    }

    // ______________________________________________________________________

    Color Color::InUnit() const
    {
        return Color(R / 255.0f, G / 255.0f, B / 255.0f, A / 255.0f);
    }

    // ______________________________________________________________________

    const Color &Color::operator= (const Color &p_Right)
    {
        R = p_Right.R;
        G = p_Right.G;
        B = p_Right.B;
        A = p_Right.A;

        return *this;
    }

    bool Color::operator== (const Color &p_Right) const
    {
        return
            (R == p_Right.R) &&
            (G == p_Right.G) &&
            (B == p_Right.B) &&
            (A == p_Right.A);
    }

    bool Color::operator!= (const Color &p_Right) const
    {
        return !operator== (p_Right);
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
