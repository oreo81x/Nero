
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API Color
    {
    public:
        float R = 0.0f;
        float G = 0.0f;
        float B = 0.0f;
        float A = 0.0f;

         Color();
         Color(const float &p_R, const float &p_G, const float &p_B, const float &p_A);
        ~Color();

        Color InUnit() const;

        const Color &operator=  (const Color &p_Right);
        bool         operator== (const Color &p_Right) const;
        bool         operator!= (const Color &p_Right) const;

    public:
        static Color White;
        static Color Black;
        static Color Green;
        static Color Blue;
        static Color Red;
        static Color Orange;
        static Color Sky;
    };
}

// ______________________________________________________________________
