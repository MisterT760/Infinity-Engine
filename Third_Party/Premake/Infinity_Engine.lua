--Solution name
workspace "Infinity_Engine"
  --Solution location and architecture
  location "..\\..\\"
  architecture "x64"

  --Solution configurations
  configurations
  {
    "Debug",
    "Release",
    "Distribution"
  }

  --Build directory
  buildDir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"
  dllDir = ""

  --Engine project
  project "Infinity_Engine"
    location "..\\..\\Bin\\Projects"
    kind "SharedLib"
    language "C++"

    --Build paths
    objdir("..\\..\\Bin\\Build\\Intermediate\\" .. buildDir .. "\\%{prj.name}")
    targetdir("..\\..\\Bin\\Build\\Binaries\\" .. buildDir .. "\\%{prj.name}")

    --Files

    --Include directories

    --Platform specifics
    filter "system:windows"
      --
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      --Platform defines
      defines
      {
        "INF_PLATFORM_WINDOWS",
        "INF_DLL"
      }

      --Dll build directory
      dllDir = "%{cfg.buildtarget.relpath}"
    filter "system:linux"

    filter "" --Remember to close the filter

    --Configurations
    filter "configurations:Debug"
      defines "INF_DEBUG"
      symbols "On"
      optimize "Off"
    filter "configurations:Release"
      defines "INF_RELEASE"
      optimize "Debug"
    filter "configurations:Distribution"
      defines "INF_DISTRIBUTION"
      optimize "Full"
    filter "" --Remember to close the filter
