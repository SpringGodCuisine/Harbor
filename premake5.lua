workspace "Harbor"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Harbor"
	location "Harbor"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}



	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

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
		symbols "On"

	filter "configurations:Debug"
		defines "HB_RELEASE"
		symbols "On"

	filter "configurations:Debug"
		defines "HB_DIST"
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
		symbols "On"

	filter "configurations:Debug"
		defines "HB_RELEASE"
		symbols "On"

	filter "configurations:Debug"
		defines "HB_DIST"
		symbols "On"

