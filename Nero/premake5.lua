
project "Nero"
    kind "SharedLib"
    
    includedirs {
        "Header",
        "SourceGLSL",
        "../Vendor/Header"
    }

    files {
        "Header/**.hpp",
        "Header/**.h",

        "Source/**.hpp",
        "Source/**.h",
        
        "Source/**.cpp",
        "Source/**.c"
    }

    links {
        "Vendor"
    }

    defines {

    }

    filter "kind:StaticLib"

        defines {
            "NERO_STATIC"
        }

    filter "kind:SharedLib"

        defines {
            "NERO_EXPORTS",
        }

    filter {}   -- end filters scope
