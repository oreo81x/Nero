
project "Vendor"
    kind "StaticLib"
    
    includedirs {
        "Header"
    }

    -- stb library files

    files {
        "Header/stb/**.hpp",
        "Header/stb/**.h",

        "Source/stb/**.hpp",
        "Source/stb/**.h",
        
        "Source/stb/**.cpp",
        "Source/stb/**.c"
    }

    defines {

    }

    -- glfw library files

    files {
        "Header/GLFW/glfw3.h",
        "Header/GLFW/glfw3native.h",

        "Source/GLFW/glfw_config.h",
        "Source/GLFW/context.c",
        "Source/GLFW/init.c",
        "Source/GLFW/input.c",
        "Source/GLFW/monitor.c",
        "Source/GLFW/vulkan.c",
        "Source/GLFW/window.c"
    }

    filter "system:linux"
        pic "On"

        files {
            "Source/GLFW/x11_init.c",
            "Source/GLFW/x11_monitor.c",
            "Source/GLFW/x11_window.c",
            "Source/GLFW/xkb_unicode.c",
            "Source/GLFW/posix_time.c",
            "Source/GLFW/posix_thread.c",
            "Source/GLFW/glx_context.c",
            "Source/GLFW/egl_context.c",
            "Source/GLFW/osmesa_context.c",
            "Source/GLFW/linux_joystick.c"
        }

        defines {
            "_GLFW_X11"
        }

    filter "system:windows"

        files {
            "Source/GLFW/win32_init.c",
            "Source/GLFW/win32_joystick.c",
            "Source/GLFW/win32_monitor.c",
            "Source/GLFW/win32_time.c",
            "Source/GLFW/win32_thread.c",
            "Source/GLFW/win32_window.c",
            "Source/GLFW/wgl_context.c",
            "Source/GLFW/egl_context.c",
            "Source/GLFW/osmesa_context.c"
        }

        defines { 
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
        }

    filter {}   -- end filters scope
    