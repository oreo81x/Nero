
// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/GLObject.hpp>

// ______________________________________________________________________

namespace Nero
{
    class NERO_API ScopeBinder
    {
    public:
         ScopeBinder(const GLObject &p_Target);
        ~ScopeBinder();

    private:
        signed int      m_OldID = 0;
        GLObjectType    m_Type;

    private:
        bool SaveID();
        bool BindID(const unsigned int &p_TargetID);
    };
}

// ______________________________________________________________________
