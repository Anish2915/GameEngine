workspace "Crab" --Solution'Crab'
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- example debug windows x64

project "Crab" --for Project Crab
    location "Crab" --Crab folder inside ProjectDir
    kind "SharedLib" --because it is dinamic library
    language "C++"
    targetdir ("bin/" ..outputdir.. "/%{prj.name}") -- project name like Crab & Warrior
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    pchheader "CrabPCH.h" -- equivalent to properties of Crab - precompiled headers - use
    pchsource "Crab/src/CrabPCH.cpp" --equivalent to properties of CrabPCH.cpp - precompiled headers - create 

    filter "system:windows" -- if statement type , untill it reach another filter or another project 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest" -- in configuration general window sdk version
        defines{
            "PLATFORM_WINDOWS",
            "BUILD_DLL"
        }

        

    filter "configurations:Debug"
        defines "CRAB_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
        defines "CRAB_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "CRAB_DISTRIBUTION"
        optimize "On"
    
project "Warrior" -- for Warrior project
    location "Warrior" --Crab folder inside ProjectDir
    kind "ConsoleApp" --because it is dinamic library
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}") -- project name like Crab & Warrior
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Crab/vendor/spdlog/include",
        "Crab/src"
    }

    links {
        "Crab"
    }

    postbuildcommands{
        "{COPY} ../bin/" .. outputdir .. "/Crab/*.dll ../bin/" .. outputdir .. "/Warrior"
    }

    filter "system:windows" -- if statement type , untill it reach another filter or another project 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest" -- in configuration general window sdk version
        defines{
            "PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "CRAB_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
        defines "CRAB_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "CRAB_DISTRIBUTION"
        optimize "On"