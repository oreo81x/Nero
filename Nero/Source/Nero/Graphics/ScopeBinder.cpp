
// ______________________________________________________________________

#include <Nero/Graphics/ScopeBinder.hpp>
#include <Nero/OpenGL.hpp>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    ScopeBinder::ScopeBinder(const GLObject &p_Target)
    {
        m_Type = p_Target.GetObjectType();

        SaveID();
        BindID(p_Target.GetNativeHandle());
    }

    ScopeBinder::~ScopeBinder()
    {
        BindID(m_OldID);
    }

    // ______________________________________________________________________

    bool ScopeBinder::SaveID()
    {
        unsigned int enumTarget  = 0;

        switch (m_Type)
        {
        case GLObjectType::ShaderProgram:
            enumTarget = GL_CURRENT_PROGRAM;
            break;

        case GLObjectType::Texture2D:
            enumTarget = GL_TEXTURE_BINDING_2D;
            break;

        case GLObjectType::Texture3D:
            enumTarget = GL_TEXTURE_BINDING_3D;
            break;

        case GLObjectType::VertexArray:
            enumTarget = GL_VERTEX_ARRAY_BINDING;
            break;

        case GLObjectType::VertexBuffer:
            enumTarget = GL_ARRAY_BUFFER_BINDING;
            break;

        case GLObjectType::IndexBuffer:
            enumTarget = GL_ELEMENT_ARRAY_BUFFER_BINDING;
            break;

        default:
            return false;
        }

        glGetIntegerv(enumTarget, &m_OldID);

        return true;
    }

    bool ScopeBinder::BindID(const unsigned int &p_TargetID)
    {
        switch (m_Type)
        {
        case GLObjectType::ShaderProgram:
            glUseProgram(p_TargetID);
            break;

        case GLObjectType::Texture2D:
            glBindTexture(GL_TEXTURE_2D, p_TargetID);
            break;

        case GLObjectType::Texture3D:
            glBindTexture(GL_TEXTURE_3D, p_TargetID);
            break;

        case GLObjectType::VertexArray:
            glBindVertexArray(p_TargetID);
            break;

        case GLObjectType::VertexBuffer:
            glBindBuffer(GL_ARRAY_BUFFER, p_TargetID);
            break;

        case GLObjectType::IndexBuffer:
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_TargetID);
            break;

        default:
            return false;
        }

        return true;
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
