
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/GLObject.hpp>
#include <Nero/Graphics/BufferUsage.hpp>
#include <Nero/Graphics/Vertex.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API VertexBuffer : public GLObject
    {
    public:
         VertexBuffer(const bool &p_CallCreate = true);
        ~VertexBuffer();

        bool Create () override;
        void Delete () override;
        bool Clean  () override;

        void Bind   () const override;
        void Unbind () const override;

        bool            IsAvailable     () const override;
        unsigned int    GetNativeHandle () const override;
        GLObjectType    GetObjectType   () const override;

        bool LoadData(const void *p_Data, const unsigned long long &p_Size, const BufferUsage &p_Usage = BufferUsage::Static);

        bool LoadData(const std::vector<float>  &p_Data, const BufferUsage &p_Usage = BufferUsage::Static);
        bool LoadData(const std::vector<Vertex> &p_Data, const BufferUsage &p_Usage = BufferUsage::Static);

        unsigned long long GetDataSize  () const;
        unsigned long long GetDataCount () const;

        const VertexBuffer &operator= (const VertexBuffer &p_Right);

    private:
        unsigned long long m_Size   = 0;
        unsigned long long m_Count  = 0;
    };
}

// ______________________________________________________________________
