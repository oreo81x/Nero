
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/Actor.hpp>
#include <Nero/Graphics/Color.hpp>
#include <Nero/Graphics/Texture.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API GameObject : public Actor
    {
    public:
        virtual ~GameObject() = 0;
        
    protected:
        Color   m_Color = Color::White;
    };
}

// ______________________________________________________________________
