
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/GLObject.hpp>
#include <Nero/Graphics/VertexBuffer.hpp>
#include <Nero/Graphics/IndexBuffer.hpp>

// ______________________________________________________________________

namespace Nero
{
    struct Layout
    {
        const unsigned int  Index   = 0;        // vertex layout index
        const unsigned int  Count   = 0;        // vertex layout components number
        const unsigned int  Stride  = 0;        // size between each vertex
        const void         *Offset  = nullptr;  // offset of layout data

        inline Layout(const unsigned int &p_Index, const unsigned int &p_Count, const unsigned int &p_Stride, const void *p_Offset)
            : Index(p_Index), Count(p_Count), Stride(p_Stride), Offset(p_Offset)
        {
            
        }
    };

    class NERO_API VertexArray : public GLObject
    {
    public:
         VertexArray(const bool &p_CallCreate = true);
        ~VertexArray();

        bool Create () override;
        void Delete () override;
        bool Clean  () override;

        void Bind   () const override;
        void Unbind () const override;

        bool            IsAvailable     () const override;
        unsigned int    GetNativeHandle () const override;
        GLObjectType    GetObjectType   () const override;

        bool LinkVBO(const VertexBuffer &p_VBO, const Layout &p_Layout) const;
        bool LinkIBO(const IndexBuffer  &p_IBO) const;

        const VertexArray &operator= (const VertexArray &p_Right);
    };
}

// ______________________________________________________________________
