
// ______________________________________________________________________

#include <Nero/Graphics/BufferUsage.hpp>
#include <Nero/OpenGL.hpp>

// ______________________________________________________________________

namespace Nero
{
    unsigned int InGLEnum(const BufferUsage &p_Usage)
    {
        return  (p_Usage == BufferUsage::Static)    ? GL_STATIC_DRAW    :
                (p_Usage == BufferUsage::Dynamic)   ? GL_DYNAMIC_DRAW   :
                (p_Usage == BufferUsage::Stream)    ? GL_STREAM_DRAW    : Error("Invalid BufferUsage Enum Value");
    }
}

// ______________________________________________________________________
