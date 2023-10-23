
// ______________________________________________________________________

#include <Nero/Graphics/IndexBuffer.hpp>
#include <Nero/Graphics/ScopeBinder.hpp>
#include <Nero/OpenGL.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    IndexBuffer::IndexBuffer(const bool &p_CallCreate)
    {
        if (p_CallCreate == false)
            return;

        if (!Create())
        {
            Error("Failed Create IndexBuffer");
        }
    }

    IndexBuffer::~IndexBuffer()
    {
        Delete();
    }

    // ______________________________________________________________________

    bool IndexBuffer::Create()
    {
        if (!glIsBuffer(m_GLTargetID))
        {
            glGenBuffers(1, &m_GLTargetID);
        }

        ScopeBinder automatic(*this);

        return glIsBuffer(m_GLTargetID);
    }

    void IndexBuffer::Delete()
    {
        glDeleteBuffers(1, &m_GLTargetID);

        m_Size          = 0;
        m_Count         = 0;
        m_GLTargetID    = 0;
    }

    bool IndexBuffer::Clean()
    {
                Delete();
        return  Create();
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_GLTargetID);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    bool IndexBuffer::IsAvailable() const
    {
        return glIsBuffer(m_GLTargetID);
    }

    unsigned int IndexBuffer::GetNativeHandle() const
    {
        return m_GLTargetID;
    }

    GLObjectType IndexBuffer::GetObjectType() const
    {
        return GLObjectType::IndexBuffer;
    }

    // ______________________________________________________________________

    bool IndexBuffer::LoadData(const void *p_Data, const unsigned long long &p_Size, const BufferUsage &p_Usage)
    {
        if (!glIsBuffer(m_GLTargetID))
        {
            return false;
        }

        ScopeBinder automatic(*this);

            glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_Size, p_Data, InGLEnum(p_Usage));

        m_Size  = p_Size;
        m_Count = p_Size / sizeof(unsigned int);

        return true;
    }

    bool IndexBuffer::LoadData(const std::vector<unsigned int> &p_Data, const BufferUsage &p_Usage)
    {
        return LoadData(p_Data.data(), p_Data.size() * sizeof(unsigned int), p_Usage);
    }

    // ______________________________________________________________________

    unsigned long long IndexBuffer::GetDataSize() const
    {
        return m_Size;
    }

    unsigned long long IndexBuffer::GetDataCount() const
    {
        return m_Count;
    }

    // ______________________________________________________________________

    const IndexBuffer &IndexBuffer::operator= (const IndexBuffer &p_Right)
    {
        glDeleteBuffers(1, &m_GLTargetID);

        m_Size          = p_Right.m_Size;
        m_Count         = p_Right.m_Count;
        m_GLTargetID    = p_Right.m_GLTargetID;

        return *this;
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
