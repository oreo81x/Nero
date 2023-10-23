
// ______________________________________________________________________

#include <Nero/Graphics/VertexArray.hpp>
#include <Nero/Graphics/ScopeBinder.hpp>
#include <Nero/OpenGL.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    VertexArray::VertexArray(const bool &p_CallCreate)
    {
        if (p_CallCreate == false)
            return;
        
        if (!Create())
        {
            Error("Failed Create VertexArray");
        }
    }

    VertexArray::~VertexArray()
    {
        Delete();
    }

    // ______________________________________________________________________

    bool VertexArray::Create()
    {
        if (!glIsVertexArray(m_GLTargetID))
        {
            glGenVertexArrays(1, &m_GLTargetID);
        }

        ScopeBinder automatic(*this);

        return glIsVertexArray(m_GLTargetID);
    }

    void VertexArray::Delete()
    {
        glDeleteVertexArrays(1, &m_GLTargetID);

        m_GLTargetID = 0;
    }

    bool VertexArray::Clean()
    {
                Delete();
        return  Create();
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_GLTargetID);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    bool VertexArray::IsAvailable() const
    {
        return glIsVertexArray(m_GLTargetID);
    }

    unsigned int VertexArray::GetNativeHandle() const
    {
        return m_GLTargetID;
    }

    GLObjectType VertexArray::GetObjectType() const
    {
        return GLObjectType::VertexArray;
    }
    
    // ______________________________________________________________________

    bool VertexArray::LinkVBO(const VertexBuffer &p_VBO, const Layout &p_Layout) const
    {
        if (!glIsVertexArray(m_GLTargetID))
        {
            return false;
        }

        ScopeBinder automaticVAO(*this);
        ScopeBinder automaticVBO(p_VBO);

            glVertexAttribPointer(p_Layout.Index, p_Layout.Count, GL_FLOAT, GL_FALSE, p_Layout.Stride, p_Layout.Offset);
            glEnableVertexAttribArray(p_Layout.Index);

        return true;
    }

    bool VertexArray::LinkIBO(const IndexBuffer &p_IBO) const
    {
        if (!glIsVertexArray(m_GLTargetID))
        {
            return false;
        }

        ScopeBinder automaticVAO(*this);
        ScopeBinder automaticIBO(p_IBO);

        /*
            - I SHOULD NOT DO IT LIKE THAT
            - I WILL FIX THE CODE LATER
            - ONLY IF I REMEMBER ..
        */

        automaticVAO.~ScopeBinder();

        return true;
    }

    // ______________________________________________________________________

    const VertexArray &VertexArray::operator= (const VertexArray &p_Right)
    {
        glDeleteVertexArrays(1, &m_GLTargetID);
        
        m_GLTargetID = p_Right.m_GLTargetID;

        return *this;
    }

}

// ______________________________________________________________________
