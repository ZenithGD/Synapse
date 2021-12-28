workspace "Synapse"
	configurations { "Debug", "Release" }

function setupProject(name, mainfile)
    project(name)
    kind "ConsoleApp"
    language "C++"
	targetdir "bin/${cfg.buildcfg}"
	
	includedirs { "lib", "vendor" }

	files { "lib/**.hpp", "lib/**.cpp", "vendor/linalg/linalg.h", mainfile }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		optimize "On"
end

project "Synapse"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/${cfg.buildcfg}"
	
	includedirs { "lib", "src", "test", "vendor" }

	files { "lib/**.hpp", "lib/**.cpp", "src/**.hpp", "src/**.cpp", "vendor/linalg/linalg.h" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		optimize "On"
	
setupProject("NeuronTest", "test/testNeuron.cpp")
