
// ______________________________________________________________________

#include <Nero/Graphics/Renderer.hpp>
#include <Nero/Graphics/Shader.hpp>
#include <Nero/Graphics/Texture.hpp>
#include <Nero/Graphics/VertexArray.hpp>
#include <Nero/Graphics/VertexBuffer.hpp>
#include <Nero/Graphics/IndexBuffer.hpp>
#include <Nero/Graphics/ScopeBinder.hpp>
#include <Nero/OpenGL.hpp>

// ______________________________________________________________________

namespace
{
    static const std::string StdVSCode =
        #include <Default.vs.glsl>
    ;

    static const std::string StdFSCode =
        #include <Default.fs.glsl>
    ;
}

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    Renderer::Renderer()
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_STENCIL_TEST);
    }

    Renderer::~Renderer()
    {
        glDisable(GL_STENCIL_TEST);
        glDisable(GL_DEPTH_TEST);
    }

    // ______________________________________________________________________

    void Renderer::AddSceneCamera(const Camera *p_Camera)
    {
        m_Camera = (Camera*)p_Camera;
    }

    // ______________________________________________________________________

    void Renderer::Clear(const glm::vec4 &p_ClearColor) const
    {
        glClearColor(p_ClearColor.r, p_ClearColor.g, p_ClearColor.b, p_ClearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Clear(const Color &p_ClearColor) const
    {
        glClearColor(p_ClearColor.InUnit().R, p_ClearColor.InUnit().G, p_ClearColor.InUnit().B, p_ClearColor.InUnit().A);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Clear(const Depth &p_ClearDepth) const
    {
        glClearDepth(p_ClearDepth.DepthValue);
        glClear(GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::Clear(const Stencil &p_ClearStenc) const
    {
        glClearStencil(p_ClearStenc.StencilValue);
        glClear(GL_STENCIL_BUFFER_BIT);
    }

    void Renderer::Clear(const Color &p_ClearColor, const Depth &p_ClearDepth) const
    {
        Clear(p_ClearColor);
        Clear(p_ClearDepth);
    }

    void Renderer::Clear(const Color &p_ClearColor, const Depth &p_ClearDepth, const Stencil &p_ClearStenc) const
    {
        Clear(p_ClearColor);
        Clear(p_ClearDepth);
        Clear(p_ClearStenc);
    }

    // ______________________________________________________________________

    void Renderer::Draw(const VertexArray &p_VAO, const VertexBuffer &p_VBO, const PrimitiveType &p_Primitive, const Shader &p_Shader, const Texture &p_Texture) const
    {
        ScopeBinder automaticVAO(p_VAO);
        ScopeBinder automaticSPO(p_Shader);
        ScopeBinder automaticTEX(p_Texture);

        glDrawArrays(InGLEnum(p_Primitive), 0, p_VBO.GetDataCount());
    }

    void Renderer::Draw(const VertexArray &p_VAO, const IndexBuffer &p_IBO, const PrimitiveType &p_Primitive, const Shader &p_Shader, const Texture &p_Texture) const
    {
        p_VAO.LinkIBO(p_IBO);

        ScopeBinder automaticVAO(p_VAO);
        ScopeBinder automaticSPO(p_Shader);
        ScopeBinder automaticTEX(p_Texture);

        glDrawElements(InGLEnum(p_Primitive), p_IBO.GetDataCount(), GL_UNSIGNED_INT, nullptr);
    }

    void Renderer::Draw(const VertexArray &p_VAO, const VertexBuffer &p_VBO, const PrimitiveType &p_Primitive, const Shader &p_Shader) const
    {
        const unsigned char pixels[4] =
        {
            255, 255, 255, 255
        };

        Texture whiteTEX;
        whiteTEX.LoadFromMemory(pixels, 1, 1, 4);

        Draw(p_VAO, p_VBO, p_Primitive, p_Shader, whiteTEX);
    }

    void Renderer::Draw(const VertexArray &p_VAO, const IndexBuffer &p_IBO, const PrimitiveType &p_Primitive, const Shader &p_Shader) const
    {
        const unsigned char pixels[4] =
        {
            255, 255, 255, 255
        };

        Texture whiteTEX;
        whiteTEX.LoadFromMemory(pixels, 1, 1, 4);

        Draw(p_VAO, p_IBO, p_Primitive, p_Shader, whiteTEX);
    }

    void Renderer::Draw(const VertexArray &p_VAO, const VertexBuffer &p_VBO, const Shader &p_Shader, const Texture &p_Texture) const
    {
        Draw(p_VAO, p_VBO, PrimitiveType::Triangles, p_Shader, p_Texture);
    }

    void Renderer::Draw(const VertexArray &p_VAO, const IndexBuffer &p_IBO, const Shader &p_Shader, const Texture &p_Texture) const
    {
        Draw(p_VAO, p_IBO, PrimitiveType::Triangles, p_Shader, p_Texture);
    }

    void Renderer::Draw(const VertexArray &p_VAO, const VertexBuffer &p_VBO, const Shader &p_Shader) const
    {
        Draw(p_VAO, p_VBO, PrimitiveType::Triangles, p_Shader);
    }

    void Renderer::Draw(const VertexArray &p_VAO, const IndexBuffer &p_IBO, const Shader &p_Shader) const
    {
        Draw(p_VAO, p_IBO, PrimitiveType::Triangles, p_Shader);
    }

    void Renderer::Draw(const std::vector<Vertex> &p_VertexData, const PrimitiveType &p_Primitive, const Texture &p_Texture) const
    {
        Shader          spo;
        VertexBuffer    vbo;
        VertexArray     vao;

        spo.LoadFromMemory(StdVSCode, StdFSCode);
        vbo.LoadData(p_VertexData);

        spo.LetUniform("u_Camera", m_Camera->GetMatrix());

        vao.LinkVBO(vbo, Layout(0, 4, sizeof(Vertex), (const void*)(offsetof(Vertex, a_Position))));
        vao.LinkVBO(vbo, Layout(1, 4, sizeof(Vertex), (const void*)(offsetof(Vertex, a_Color))));
        vao.LinkVBO(vbo, Layout(2, 2, sizeof(Vertex), (const void*)(offsetof(Vertex, a_Coord))));

        Draw(vao, vbo, p_Primitive, spo, p_Texture);
    }

    void Renderer::Draw(const std::vector<Vertex> &p_VertexData, const PrimitiveType &p_Primitive) const
    {
        const unsigned char pixels[4] =
        {
            255, 255, 255, 255
        };

        Texture whiteTEX;
        whiteTEX.LoadFromMemory(pixels, 1, 1, 4);

        Draw(p_VertexData, p_Primitive, whiteTEX);
    }

    void Renderer::Draw(const std::vector<Vertex> &p_VertexData, const Texture &p_Texture) const
    {
        Draw(p_VertexData, PrimitiveType::Triangles, p_Texture);
    }

    void Renderer::Draw(const std::vector<Vertex> &p_VertexData) const
    {
        Draw(p_VertexData, PrimitiveType::Triangles);
    }

    // ______________________________________________________________________

    void Renderer::Draw(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData, const PrimitiveType &p_Primitive, const Texture &p_Texture) const
    {
        Shader          spo;
        VertexArray     vao;
        VertexBuffer    vbo;
        IndexBuffer     ibo;

        spo.LoadFromMemory(StdVSCode, StdFSCode);
        spo.LetUniform("u_Camera", m_Camera->GetMatrix());

        vbo.LoadData(p_VertexData);
        ibo.LoadData(p_IndexData);
        
        vao.LinkVBO(vbo, Layout(0, 4, sizeof(Vertex), (const void*)(offsetof(Vertex, a_Position))));
        vao.LinkVBO(vbo, Layout(1, 4, sizeof(Vertex), (const void*)(offsetof(Vertex, a_Color))));
        vao.LinkVBO(vbo, Layout(2, 2, sizeof(Vertex), (const void*)(offsetof(Vertex, a_Coord))));

        vao.LinkIBO(ibo);

        Draw(vao, ibo, p_Primitive, spo, p_Texture);
    }

    void Renderer::Draw(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData, const PrimitiveType &p_Primitive) const
    {
        const unsigned char pixels[4] =
        {
            255, 255, 255, 255
        };

        Texture whiteTEX;
        whiteTEX.LoadFromMemory(pixels, 1, 1, 4);

        Draw(p_VertexData, p_IndexData, p_Primitive, whiteTEX);
    }
        
    void Renderer::Draw(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData, const Texture &p_Texture) const
    {
        Draw(p_VertexData, p_IndexData, PrimitiveType::Triangles, p_Texture);
    }

    void Renderer::Draw(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData) const
    {
        Draw(p_VertexData, p_IndexData, PrimitiveType::Triangles);
    }

    void Renderer::Draw(const RenderData &p_RenderData, const Texture &p_Texture) const
    {
        if (p_RenderData.IndexData.size() != 0)
        {
            Draw(p_RenderData.VertexData, p_RenderData.IndexData, p_RenderData.Primitive, p_Texture);
            return;
        }

        Draw(p_RenderData.VertexData, p_RenderData.Primitive, p_Texture);
    }

    void Renderer::Draw(const RenderData &p_RenderData) const
    {
        if (RenderData.IndexData.size() != 0)
        {
            Draw(p_RenderData.VertexData, p_RenderData.IndexData, p_RenderData.Primitive);
            return;
        }

        Draw(p_RenderData.VertexData, p_RenderData.Primitive);
    }
    
    // ______________________________________________________________________

}

// ______________________________________________________________________
