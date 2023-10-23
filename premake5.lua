workspace "Nero"
    location "Build"

    -- configurations
    configurations {
        "Debug", "Release"
    }

    -- platforms
    platforms {
        "OS64", "OS86"
    }

    -- Windows system filter
    filter "system:Windows"

        targetdir   "Binaries/%{cfg.buildcfg}Windows%{cfg.platform}/"--%{prj.name}/"
        objdir      "BinariesOBJ/%{cfg.buildcfg}Windows%{cfg.platform}/%{prj.name}/"

    -- Linux system filter
    filter "system:Linux"

        targetdir   "Binaries/%{cfg.buildcfg}Linux%{cfg.platform}/%{prj.name}/"
        objdir      "BinariesOBJ/%{cfg.buildcfg}Linux%{cfg.platform}/%{prj.name}/"

    -- Debug configuration filter
    filter "configurations:Debug"

        runtime         "Debug"
        symbols         "On"
        optimize        "Off"
        targetprefix    ""
        targetsuffix    "Debug"

    -- Release configuration filter
    filter "configurations:Release"

        runtime         "Release"
        symbols         "On"
        optimize        "On"
        targetprefix    ""
        targetsuffix    ""

    -- OS64 platform filter
    filter "platforms:OS64"

        architecture "x86_64"

    -- OS86 platform filter
    filter "platforms:OS86"

        architecture "x86"

    -- StaticLib kind filter
    filter "kind:StaticLib"

        targetsuffix "Static"

    -- StaticLib kind and Debug configuration filter
    filter {"configurations:Debug", "kind:StaticLib"}

        targetsuffix "StaticDebug"

    filter {}   -- end filters scope

    -- default project level settings

    language        "C++"
    cppdialect      "C++17"
    staticruntime   "On"
    systemversion   "latest"

    -- including projects

    startproject "Testing"

    include "Nero"
    include "Testing"
    include "Vendor"
    
    -- costum new actions

    newaction {
        trigger     = "clean",
        description = "clean IDE files",
        execute     = function ()
            os.rmdir("Build")
        end
    }

    newaction {
        trigger     = "cleanbin",
        description = "clean compiled binaries",
        execute     = function ()
            os.rmdir("Binaries")
            os.rmdir("BinariesOBJ")
        end
    }

    newaction {
        trigger     = "cleanall",
        description = "clean compiled binaries and IDE files",
        execute     = function ()
            os.rmdir("Build")
            os.rmdir("Binaries")
            os.rmdir("BinariesOBJ")
        end
    }
    