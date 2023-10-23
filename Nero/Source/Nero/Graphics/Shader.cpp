
// ______________________________________________________________________

#include <Nero/Graphics/Shader.hpp>
#include <Nero/Graphics/ScopeBinder.hpp>
#include <Nero/OpenGL.hpp>
#include <fstream>

// ______________________________________________________________________

namespace
{
    std::string GetFileContent(const std::string &p_Filename)
    {
        std::ifstream in(p_Filename, std::ios::in | std::ios::binary);
        if (in)
        {
            std::string buffer;

            in.seekg(0, in.end);
            buffer.resize(in.tellg());
            in.seekg(0, in.beg);

            in.read(&buffer[0], buffer.size());
            in.close();

            return buffer;
        }

        return "";
    }
}

namespace Nero
{

    // ______________________________________________________________________

    Shader::Shader(const bool &p_CallCreate)
    {
        if (p_CallCreate == false)
            return;
        
        if (!Create())
        {
            Error("Failed Create Shader");
        }
    }

    Shader::~Shader()
    {
        Delete();
    }

    // ______________________________________________________________________

    bool Shader::Create()
    {
        if (!glIsProgram(m_GLTargetID))
        {
            m_GLTargetID = glCreateProgram();
        }

        ScopeBinder automatic(*this);

        return glIsProgram(m_GLTargetID);
    }

    void Shader::Delete()
    {
        glDeleteProgram(m_GLTargetID);

        m_UniformLocationCache.clear();
        m_GLTargetID = 0;
    }

    bool Shader::Clean()
    {
                Delete();
        return  Create();
    }

    void Shader::Bind() const
    {
        glUseProgram(m_GLTargetID);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    bool Shader::IsAvailable() const
    {
        return glIsProgram(m_GLTargetID);
    }

    unsigned int Shader::GetNativeHandle() const
    {
        return m_GLTargetID;
    }

    GLObjectType Shader::GetObjectType() const
    {
        return GLObjectType::ShaderProgram;
    }

    // ______________________________________________________________________

    bool Shader::LoadFromMemory(const std::string &p_ShaderCode, const ShaderType &p_ShaderType)
    {
        return  (p_ShaderType == ShaderType::Vertex)    ? Compile(&p_ShaderCode[0], nullptr, nullptr) :
                (p_ShaderType == ShaderType::Fragment)  ? Compile(nullptr, &p_ShaderCode[0], nullptr) :
                (p_ShaderType == ShaderType::Geometry)  ? Compile(nullptr, nullptr, &p_ShaderCode[0]) : false;
    }

    bool Shader::LoadFromFile(const std::string &p_ShaderFile, const ShaderType &p_ShaderType)
    {
        return LoadFromMemory(GetFileContent(p_ShaderFile), p_ShaderType);
    }

    // ______________________________________________________________________

    bool Shader::LoadFromMemory(const std::string &p_VertexShaderCode, const std::string &p_FragmentShaderCode)
    {
        return Compile(&p_VertexShaderCode[0], &p_FragmentShaderCode[0], nullptr);
    }

    bool Shader::LoadFromFile(const std::string &p_VertexShaderFile, const std::string &p_FragmentShaderFile)
    {
        return LoadFromMemory(GetFileContent(p_VertexShaderFile), GetFileContent(p_FragmentShaderFile));
    }

    // ______________________________________________________________________

    bool Shader::LoadFromMemory(const std::string &p_VertexShaderCode, const std::string &p_FragmentShaderCode, const std::string &p_GeometryShaderCode)
    {
        return Compile(&p_VertexShaderCode[0], &p_FragmentShaderCode[0], &p_GeometryShaderCode[0]);
    }

    bool Shader::LoadFromFile(const std::string &p_VertexShaderFile, const std::string &p_FragmentShaderFile, const std::string &p_GeometryShaderFile)
    {
        return LoadFromMemory(GetFileContent(p_VertexShaderFile), GetFileContent(p_FragmentShaderFile), GetFileContent(p_GeometryShaderFile));
    }

    // ______________________________________________________________________

    signed int Shader::GetUniformLocation(const std::string &p_UniformName) const
    {
        if (m_UniformLocationCache.find(p_UniformName) != m_UniformLocationCache.end())
        {
            return m_UniformLocationCache[p_UniformName];
        }

        signed int location = glGetUniformLocation(m_GLTargetID, p_UniformName.c_str());

        if (location != -1)
        {
            m_UniformLocationCache[p_UniformName] = location;
        }

        return location;
    }

    // ______________________________________________________________________

    void Shader::LetUniform(const std::string &p_UniformName, const bool &p_Value) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniform1i(location, p_Value);
        }
    }

    void Shader::LetUniform(const std::string &p_UniformName, const float &p_Value) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniform1f(location, p_Value);
        }
    }

    void Shader::LetUniform(const std::string &p_UniformName, const signed int &p_Value) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniform1i(location, p_Value);
        }
    }

    void Shader::LetUniform(const std::string &p_UniformName, const unsigned int &p_Value) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniform1ui(location, p_Value);
        }
    }

    // ______________________________________________________________________

    void Shader::LetUniform(const std::string &p_UniformName, const glm::mat2 &p_Matrix) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniformMatrix2fv(location, 1, GL_FALSE, &p_Matrix[0][0]);
        }
    }

    void Shader::LetUniform(const std::string &p_UniformName, const glm::mat3 &p_Matrix) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniformMatrix3fv(location, 1, GL_FALSE, &p_Matrix[0][0]);
        }
    }

    void Shader::LetUniform(const std::string &p_UniformName, const glm::mat4 &p_Matrix) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniformMatrix4fv(location, 1, GL_FALSE, &p_Matrix[0][0]);
        }
    }

    // ______________________________________________________________________

    void Shader::LetUniform(const std::string &p_UniformName, const glm::vec2 &p_Vector) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniform2fv(location, 1, &p_Vector[0]);
        }
    }

    void Shader::LetUniform(const std::string &p_UniformName, const glm::vec3 &p_Vector) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniform3fv(location, 1, &p_Vector[0]);
        }
    }

    void Shader::LetUniform(const std::string &p_UniformName, const glm::vec4 &p_Vector) const
    {
        signed int location = GetUniformLocation(p_UniformName);

        if (location != -1)
        {
            ScopeBinder automatic(*this);
            glUniform4fv(location, 1, &p_Vector[0]);
        }
    }

    // ______________________________________________________________________

    bool Shader::Compile(const char *p_VertexShaderCode, const char *p_FragmentShaderCode, const char *p_GeometryShaderCode)
    {
        if (!Clean())
        {
            return false;
        }

        unsigned int vertShaderID = 0;
        unsigned int fragShaderID = 0;
        unsigned int geomShaderID = 0;

        if (p_VertexShaderCode != nullptr)
        {
            vertShaderID = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertShaderID, 1, &p_VertexShaderCode, nullptr);
            glCompileShader(vertShaderID);

            if (vertShaderID)
                glAttachShader(m_GLTargetID, vertShaderID);
        }

        if (p_FragmentShaderCode != nullptr)
        {
            fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragShaderID, 1, &p_FragmentShaderCode, nullptr);
            glCompileShader(fragShaderID);

            if (fragShaderID)
                glAttachShader(m_GLTargetID, fragShaderID);
        }

        if (p_GeometryShaderCode != nullptr)
        {
            geomShaderID = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(geomShaderID, 1, &p_GeometryShaderCode, nullptr);
            glCompileShader(geomShaderID);

            if (geomShaderID)
                glAttachShader(m_GLTargetID, geomShaderID);
        }

        glLinkProgram(m_GLTargetID);

        glDetachShader(m_GLTargetID, vertShaderID);
        glDetachShader(m_GLTargetID, fragShaderID);
        glDetachShader(m_GLTargetID, geomShaderID);

        glDeleteShader(vertShaderID);
        glDeleteShader(fragShaderID);
        glDeleteShader(geomShaderID);

        return true;
    }

    // ______________________________________________________________________

    const Shader &Shader::operator= (const Shader &p_Shader)
    {
        glDeleteProgram(m_GLTargetID);

        m_GLTargetID            = p_Shader.m_GLTargetID;
        m_UniformLocationCache  = p_Shader.m_UniformLocationCache;

        return *this;
    }

    // ______________________________________________________________________

    unsigned int InGLEnum(const ShaderType &p_Type)
    {
        return  (p_Type == ShaderType::Vertex)      ? GL_VERTEX_SHADER      :
                (p_Type == ShaderType::Fragment)    ? GL_FRAGMENT_SHADER    :
                (p_Type == ShaderType::Geometry)    ? GL_GEOMETRY_SHADER    : Error("Invalid ShaderType Enum Value");
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
