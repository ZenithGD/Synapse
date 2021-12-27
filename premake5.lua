workspace "Synapse"
	configurations { "Debug", "Release" }

project "Synapse"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/${cfg.buildcfg}"
	
	includedirs { "lib", "src", "test" }

	files { "lib/**.hpp", "lib/**.cpp", "src/**.hpp", "src/**.cpp", "vendor/linalg/linalg.h" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		optimize "On"
	
