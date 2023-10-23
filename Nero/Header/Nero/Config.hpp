
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// ______________________________________________________________________

#ifdef _WIN32

    #define NERO_SYSTEM_WINDOWS
    #ifndef NOMINMAX

        #define NOMINMAX

    #endif

#elif defined(__unix__)

    #ifdef __linux__

        #define NERO_SYSTEM_LINUX

    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernal__)

        #define NERO_SYSTEM_FREEBSD

    #elif defined(__OpenBSD__)

        #define NERO_SYSTEM_OPENBSD

    #elif defined(__NetBSD__)

        #define NERO_SYSTEM_NETBSD

    #else

        #error This UNIX system is not supported by Nero

    #endif

#else

    #error This system is not supported by Nero

#endif

// ______________________________________________________________________

#ifdef NDEBUG

    #define NERO_RELEASE

#else

    #define NERO_DEBUG

#endif

// ______________________________________________________________________

#ifdef NERO_STATIC

    #define NERO_API_EXPORT
    #define NERO_API_IMPORT

#else

    #ifdef NERO_SYSTEM_WINDOWS

        #define NERO_API_EXPORT __declspec(dllexport)
        #define NERO_API_IMPORT __declspec(dllimport)

        #ifdef _MSC_VER

            #pragma warning(disable: 4251)

        #endif

    #else

        #ifdef __GNUC__

            #define NERO_API_EXPORT __attribute__((__visibility__("default")))
            #define NERO_API_IMPORT __attribute__((__visibility__("default")))

        #else

            #error Unknown shared lib export and import semantics by Nero for this compiler

        #endif

    #endif

#endif

// ______________________________________________________________________

#ifdef NERO_EXPORTS

    #define NERO_API NERO_API_EXPORT

#else

    #define NERO_API NERO_API_IMPORT

#endif

// ______________________________________________________________________

namespace Nero
{
    bool NERO_API Info  (const std::string &p_Text);
    bool NERO_API Warn  (const std::string &p_Text);
    bool NERO_API Error (const std::string &p_Text);
    bool NERO_API Fatal (const std::string &p_Text);
}

// ______________________________________________________________________
