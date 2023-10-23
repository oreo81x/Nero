
// ______________________________________________________________________

#include <Nero/Graphics/Texture.hpp>
#include <Nero/Graphics/ScopeBinder.hpp>
#include <Nero/OpenGL.hpp>
#include <stb/stb_image.h>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    Texture::Texture(const bool &p_CallCreate)
    {
        if (p_CallCreate == false)
            return;

        if (!Create())
        {
            Error("Failed Create Texture");
        }
    }

    Texture::Texture(const unsigned char *p_Pixels, const unsigned int &p_Width, const unsigned int &p_Height, const unsigned int &p_Channels) : Texture()
    {
        LoadFromMemory(p_Pixels, p_Width, p_Height, p_Channels);
    }

    Texture::Texture(const std::string &p_Filename) : Texture()
    {
        LoadFromFile(p_Filename);
    }

    Texture::~Texture()
    {
        Delete();
    }

    // ______________________________________________________________________

    bool Texture::Create()
    {
        if (!glIsTexture(m_GLTargetID))
        {
            glGenTextures(1, &m_GLTargetID);
        }

        ScopeBinder automatic(*this);

        return glIsTexture(m_GLTargetID);
    }

    void Texture::Delete()
    {
        glDeleteTextures(1, &m_GLTargetID);

        m_Smooth = false;
        m_Repeat = false;
        m_GLTargetID = 0;
    }

    bool Texture::Clean()
    {
                Delete();
        return  Create();
    }

    void Texture::Bind() const
    {
        glBindTexture(GL_TEXTURE_2D, m_GLTargetID);
    }

    void Texture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    bool Texture::IsAvailable() const
    {
        return glIsTexture(m_GLTargetID);
    }

    unsigned int Texture::GetNativeHandle() const
    {
        return m_GLTargetID;
    }

    GLObjectType Texture::GetObjectType() const
    {
        return GLObjectType::Texture2D;
    }

    // ______________________________________________________________________

    bool Texture::LoadFromMemory(const unsigned char *p_Pixels, const unsigned int &p_Width, const unsigned int &p_Height, const unsigned int &p_Channels)
    {
        if (!glIsTexture(m_GLTargetID))
        {
            return false;
        }

        unsigned int formatEnumValue =  (p_Channels == 2)   ? GL_RG     :
                                        (p_Channels == 3)   ? GL_RGB    :
                                        (p_Channels == 4)   ? GL_RGBA   : 0;

        LetSmooth(m_Smooth);
        LetRepeat(m_Repeat);

        ScopeBinder automatic(*this);

            glTexImage2D(GL_TEXTURE_2D, 0, formatEnumValue, p_Width, p_Height, 0, formatEnumValue, GL_UNSIGNED_BYTE, (const void*)p_Pixels);
            glGenerateMipmap(GL_TEXTURE_2D);

        return true;
    }

    bool Texture::LoadFromFile(const std::string &p_Filename)
    {
        signed int width = 0, height = 0, channels = 0;

        stbi_set_flip_vertically_on_load(true);
        unsigned char *pixels = stbi_load(p_Filename.c_str(), &width, &height, &channels, 0);

        LoadFromMemory(pixels, width, height, channels);

        stbi_image_free(pixels);

        return true;
    }

    // ______________________________________________________________________

    void Texture::LetSmooth(const bool &p_Smooth)
    {
        if (!glIsTexture(m_GLTargetID))
        {
            Error("Can't Change Texture Smooth Flag To " + std::to_string(p_Smooth) + ", The Object Is Not Available");
            return;
        }

        ScopeBinder automatic(*this);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (p_Smooth) ? GL_LINEAR : GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (p_Smooth) ? GL_LINEAR : GL_NEAREST);

        m_Smooth = p_Smooth;
    }

    void Texture::LetRepeat(const bool &p_Repeat)
    {
        if (!glIsTexture(m_GLTargetID))
        {
            Error("Can't Change Texture Repeat Flag To " + std::to_string(p_Repeat) + " The Object Is Not Available");
            return;
        }

        ScopeBinder automatic(*this);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (m_Repeat) ? GL_REPEAT : GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (m_Repeat) ? GL_REPEAT : GL_CLAMP_TO_EDGE);

        m_Repeat = p_Repeat;
    }

    // ______________________________________________________________________

    bool Texture::GetSmooth() const
    {
        return m_Smooth;
    }

    bool Texture::GetRepeat() const
    {
        return m_Repeat;
    }

    // ______________________________________________________________________

    const Texture &Texture::operator= (const Texture &p_Right)
    {
        glDeleteTextures(1, &m_GLTargetID);

        m_Smooth        = p_Right.m_Smooth;
        m_Repeat        = p_Right.m_Repeat;
        m_GLTargetID    = p_Right.m_GLTargetID;

        return *this;
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
