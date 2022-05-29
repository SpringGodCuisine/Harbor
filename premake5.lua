workspace "Harbor"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Harbor/vendor/GLFW/include"

include "Harbor/vendor/GLFW"

project "Harbor"
	location "Harbor"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hbpch.h"
	pchsource "Harbor/src/hbpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}



	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HB_PLATFROM_WINDOWS",
			"HB_BUILD_DLL",
		}

		postbuildcommands
		{
			{"{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
		}

	filter "configurations:Debug"
		defines "HB_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Debug"
		defines "HB_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Debug"
		defines "HB_DIST"
		buildoptions "/MD"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Harbor/vendor/spdlog/include",
		"Harbor/src"
	}

	links
	{
		"Harbor"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"HB_PLATFROM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HB_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Debug"
		defines "HB_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Debug"
		defines "HB_DIST"
		buildoptions "/MD"
		symbols "On"

