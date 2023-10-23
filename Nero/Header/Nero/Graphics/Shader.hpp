
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/GLObject.hpp>

// ______________________________________________________________________

namespace Nero
{
    enum class ShaderType : unsigned char
    {
        Vertex      = 0,
        Fragment    = 1,
        Geometry    = 2
    };

    class NERO_API Shader : public GLObject
    {
    public:
         Shader(const bool &p_CallCreate = true);
        ~Shader();

        bool Create () override;
        void Delete () override;
        bool Clean  () override;

        void Bind   () const override;
        void Unbind () const override;

        bool            IsAvailable     () const override;
        unsigned int    GetNativeHandle () const override;
        GLObjectType    GetObjectType   () const override;

        bool LoadFromMemory (const std::string &p_ShaderCode, const ShaderType &p_ShaderType);
        bool LoadFromFile   (const std::string &p_ShaderFile, const ShaderType &p_ShaderType);

        bool LoadFromMemory (const std::string &p_VertexShaderCode, const std::string &p_FragmentShaderCode);
        bool LoadFromFile   (const std::string &p_VertexShaderFile, const std::string &p_FragmentShaderFile);

        bool LoadFromMemory (const std::string &p_VertexShaderCode, const std::string &p_FragmentShaderCode, const std::string &p_GeometryShaderCode);
        bool LoadFromFile   (const std::string &p_VertexShaderFile, const std::string &p_FragmentShaderFile, const std::string &p_GeometryShaderFile);

        signed int GetUniformLocation(const std::string &p_UniformName) const;

        void LetUniform(const std::string &p_UniformName, const bool            &p_Value) const;
        void LetUniform(const std::string &p_UniformName, const float           &p_Value) const;
        void LetUniform(const std::string &p_UniformName, const signed int      &p_Value) const;
        void LetUniform(const std::string &p_UniformName, const unsigned int    &p_Value) const;

        void LetUniform(const std::string &p_UniformName, const glm::mat2 &p_Matrix) const;
        void LetUniform(const std::string &p_UniformName, const glm::mat3 &p_Matrix) const;
        void LetUniform(const std::string &p_UniformName, const glm::mat4 &p_Matrix) const;

        void LetUniform(const std::string &p_UniformName, const glm::vec2 &p_Vector) const;
        void LetUniform(const std::string &p_UniformName, const glm::vec3 &p_Vector) const;
        void LetUniform(const std::string &p_UniformName, const glm::vec4 &p_Vector) const;

        const Shader &operator= (const Shader &p_Shader);

    private:
        mutable std::unordered_map<std::string, signed int> m_UniformLocationCache;

    private:
        bool Compile(const char *p_VertexShaderCode, const char *p_FragmentShaderCode, const char *p_GeometryShaderCode);
    };

    unsigned int InGLEnum(const ShaderType &p_Type);
}

// ______________________________________________________________________
