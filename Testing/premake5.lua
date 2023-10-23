
project "Testing"
    kind "ConsoleApp"
    
    includedirs {
        "Header",
        "../Nero/Header",
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
        "Nero",
        "Vendor"
    }

    defines {

    }
