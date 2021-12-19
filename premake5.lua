workspace "Synapse"
	configurations { "Debug", "Release" }

project "Synapse"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/${cfg.buildcfg}"
	
	includedirs { "lib", "src" }

	files { "**.hpp", "**.cpp" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		optimize "On"
	
