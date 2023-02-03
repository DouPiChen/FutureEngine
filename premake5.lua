workspace "FutureEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "FutureEngine/ThirdParty"

project "FutureEngine"
	location "FutureEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir )
	objdir ("bin-int/" .. outputdir )

	pchheader "fepch.h"
	pchsource "%{prj.name}/src/fepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/ThirdParty/spdlog/include",
		"%{prj.name}/ThirdParty/GLFW/include"
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
			"FE_PLATFORM_WINDOWS",
			"FE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir.. "/FutureSandbox")
		}

	filter "configurations:Debug"
		defines "FE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "FE_DIST"
		optimize "On"

project "FutureSandbox"
	location "FutureSandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir )
	objdir ("bin-int/" .. outputdir )

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

	}

	includedirs
	{
		"FutureEngine/ThirdParty/spdlog/include",
		"FutureEngine/src"
	}

	links
	{
		"FutureEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "FE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "FE_DIST"
		optimize "On"
		
