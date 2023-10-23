
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/GLObject.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API Texture : public GLObject
    {
    public:
         Texture(const bool &p_CallCreate = true);
         Texture(const unsigned char *p_Pixels, const unsigned int &p_Width, const unsigned int &p_Height, const unsigned int &p_Channels);
         Texture(const std::string &p_Filename);
        ~Texture();

        bool Create () override;
        void Delete () override;
        bool Clean  () override;

        void Bind   () const override;
        void Unbind () const override;

        bool            IsAvailable     () const override;
        unsigned int    GetNativeHandle () const override;
        GLObjectType    GetObjectType   () const override;

        bool LoadFromMemory (const unsigned char *p_Pixels, const unsigned int &p_Width, const unsigned int &p_Height, const unsigned int &p_Channels);
        bool LoadFromFile   (const std::string &p_Filename);

        void LetSmooth(const bool &p_Smooth);
        void LetRepeat(const bool &p_Repeat);

        bool GetSmooth() const;
        bool GetRepeat() const;

        const Texture &operator= (const Texture &p_Right);

    private:
        bool m_Smooth = false;
        bool m_Repeat = false;
    };
}

// ______________________________________________________________________
