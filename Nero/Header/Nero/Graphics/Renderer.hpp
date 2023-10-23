
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/Color.hpp>
#include <Nero/Graphics/Depth.hpp>
#include <Nero/Graphics/Stencil.hpp>
#include <Nero/Graphics/Vertex.hpp>
#include <Nero/Graphics/PrimitiveType.hpp>
#include <Nero/Graphics/Shader.hpp>
#include <Nero/Graphics/Texture.hpp>
#include <Nero/Graphics/VertexArray.hpp>
#include <Nero/Graphics/VertexBuffer.hpp>
#include <Nero/Graphics/IndexBuffer.hpp>
#include <Nero/Graphics/Camera.hpp>
#include <Nero/Graphics/RenderData.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API Renderer
    {
    public:
         Renderer();
        ~Renderer();

        void AddSceneCamera(const Camera *p_Camera);

        void Clear(const glm::vec4  &p_ClearColor) const;
        void Clear(const Color      &p_ClearColor) const;
        void Clear(const Depth      &p_ClearDepth) const;
        void Clear(const Stencil    &p_ClearStenc) const;
        void Clear(const Color      &p_ClearColor, const Depth &p_ClearDepth) const;
        void Clear(const Color      &p_ClearColor, const Depth &p_ClearDepth, const Stencil &p_ClearStenc) const;

        void Draw(const VertexArray &p_VAO, const VertexBuffer  &p_VBO, const PrimitiveType &p_Primitive, const Shader &p_Shader, const Texture &p_Texture) const;
        void Draw(const VertexArray &p_VAO, const IndexBuffer   &p_IBO, const PrimitiveType &p_Primitive, const Shader &p_Shader, const Texture &p_Texture) const;

        void Draw(const VertexArray &p_VAO, const VertexBuffer  &p_VBO, const PrimitiveType &p_Primitive, const Shader &p_Shader) const;
        void Draw(const VertexArray &p_VAO, const IndexBuffer   &p_IBO, const PrimitiveType &p_Primitive, const Shader &p_Shader) const;

        void Draw(const VertexArray &p_VAO, const VertexBuffer  &p_VBO, const Shader &p_Shader, const Texture &p_Texture) const;
        void Draw(const VertexArray &p_VAO, const IndexBuffer   &p_IBO, const Shader &p_Shader, const Texture &p_Texture) const;

        void Draw(const VertexArray &p_VAO, const VertexBuffer  &p_VBO, const Shader &p_Shader) const;
        void Draw(const VertexArray &p_VAO, const IndexBuffer   &p_IBO, const Shader &p_Shader) const;

        void Draw(const std::vector<Vertex> &p_VertexData, const PrimitiveType &p_Primitive, const Texture &p_Texture) const;
        void Draw(const std::vector<Vertex> &p_VertexData, const PrimitiveType &p_Primitive) const;

        void Draw(const std::vector<Vertex> &p_VertexData, const Texture &p_Texture) const;
        void Draw(const std::vector<Vertex> &p_VertexData) const;
        
        void Draw(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData, const PrimitiveType &p_Primitive, const Texture &p_Texture) const;
        void Draw(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData, const PrimitiveType &p_Primitive) const;
        
        void Draw(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData, const Texture &p_Texture) const;
        void Draw(const std::vector<Vertex> &p_VertexData, const std::vector<unsigned int> &p_IndexData) const;

        void Draw(const RenderData &p_RenderData, const Texture &p_Texture) const;
        void Draw(const RenderData &p_RenderData) const;

    private:
        Camera *m_Camera = nullptr;
    };
}

// ______________________________________________________________________
