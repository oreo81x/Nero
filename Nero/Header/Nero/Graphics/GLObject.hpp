
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>

// ______________________________________________________________________

namespace Nero
{
    enum class GLObjectType
    {
        ShaderProgram   = 0,
        Texture2D       = 1,
        Texture3D       = 2,
        VertexArray     = 3,
        VertexBuffer    = 4,
        IndexBuffer     = 5
    };

    class NERO_API GLObject
    {
    public:
        virtual ~GLObject() = 0;
        
        virtual bool Create () = 0;
        virtual void Delete () = 0;
        virtual bool Clean  () = 0;

        virtual void Bind   () const = 0;
        virtual void Unbind () const = 0;

        virtual bool            IsAvailable     () const = 0;
        virtual unsigned int    GetNativeHandle () const = 0;
        virtual GLObjectType    GetObjectType   () const = 0;

    protected:
        unsigned int m_GLTargetID = 0;
    };
}

// ______________________________________________________________________
