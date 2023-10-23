
// ______________________________________________________________________

#include <Nero/Graphics/VertexBuffer.hpp>
#include <Nero/Graphics/ScopeBinder.hpp>
#include <Nero/OpenGL.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    VertexBuffer::VertexBuffer(const bool &p_CallCreate)
    {
        if (p_CallCreate == false)
            return;
        
        if (!Create())
        {
            Error("Failed Create VertexBuffer");
        }
    }

    VertexBuffer::~VertexBuffer()
    {
        Delete();
    }

    // ______________________________________________________________________

    bool VertexBuffer::Create()
    {
        if (!glIsBuffer(m_GLTargetID))
        {
            glGenBuffers(1, &m_GLTargetID);
        }

        ScopeBinder automatic(*this);

        return glIsBuffer(m_GLTargetID);
    }

    void VertexBuffer::Delete()
    {
        glDeleteBuffers(1, &m_GLTargetID);

        m_Size          = 0;
        m_Count         = 0;
        m_GLTargetID    = 0;
    }

    bool VertexBuffer::Clean()
    {
                Delete();
        return  Create();
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_GLTargetID);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    bool VertexBuffer::IsAvailable() const
    {
        return glIsBuffer(m_GLTargetID);
    }

    unsigned int VertexBuffer::GetNativeHandle() const
    {
        return m_GLTargetID;
    }

    GLObjectType VertexBuffer::GetObjectType() const
    {
        return GLObjectType::VertexBuffer;
    }

    // ______________________________________________________________________

    bool VertexBuffer::LoadData(const void *p_Data, const unsigned long long &p_Size, const BufferUsage &p_Usage)
    {
        if (!glIsBuffer(m_GLTargetID))
        {
            return false;
        }

        ScopeBinder automatic(*this);

            glBufferData(GL_ARRAY_BUFFER, p_Size, p_Data, InGLEnum(p_Usage));

        m_Size  = p_Size;
        m_Count = p_Size / sizeof(float);

        return true;
    }

    bool VertexBuffer::LoadData(const std::vector<float> &p_Data, const BufferUsage &p_Usage)
    {
        return LoadData(p_Data.data(), p_Data.size() * sizeof(float), p_Usage);
    }

    bool VertexBuffer::LoadData(const std::vector<Vertex> &p_Data, const BufferUsage &p_Usage)
    {
        return LoadData(p_Data.data(), p_Data.size() * sizeof(Vertex), p_Usage);
    }

    // ______________________________________________________________________

    unsigned long long VertexBuffer::GetDataSize() const
    {
        return m_Size;
    }

    unsigned long long VertexBuffer::GetDataCount() const
    {
        return m_Count;
    }

    // ______________________________________________________________________

    const VertexBuffer &VertexBuffer::operator= (const VertexBuffer &p_Right)
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
