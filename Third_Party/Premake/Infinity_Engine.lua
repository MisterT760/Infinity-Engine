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

  --Build directory
  buildDir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"
  dllDir = "Undefined"

  --Engine project
  project "Infinity_Engine"
    location "..\\..\\Binaries\\Win64"
    kind "SharedLib"
    language "C++"

    --Build paths
    objdir("..\\..\\Build\\" .. buildDir .. "\\Intermediate")
    targetdir("..\\..\\Build\\" .. buildDir)

    --Files
    files
    {
      "..\\..\\Source\\Runtime\\Engine\\**.cpp",
      "..\\..\\Source\\Runtime\\Engine\\**.h",
    }

    --Include directories
    includedirs
    {
      "..\\..\\Source\\Third_Party\\spdlog\\include",
    }

    --Platform specifics
    filter "system:windows"
      --Basic windows setup
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

  project "Infinity_Editor"
    location "..\\..\\Binaries\\Win64"
    kind "ConsoleApp"
    language "C++"

    --Build paths
    objdir("..\\..\\Build\\" .. buildDir .. "\\Intermediate")
    targetdir("..\\..\\Build\\" .. buildDir)

    --Files
    files
    {
      "..\\..\\Source\\Runtime\\Editor\\**.cpp",
      "..\\..\\Source\\Runtime\\Editor\\**.h",
    }

    includedirs
    {
      "..\\..\\Source\\Third_Party\\spdlog\\include",
      "..\\..\\Source\\Runtime\\Engine"
    }

    links
    {
      "Infinity_Engine"
    }

    filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines
      {
        "INF_PLATFORM_WINDOWS"
      }
    filter "system:linux"
    filter ""
