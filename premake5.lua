workspace "Synapse"
	configurations { "Debug", "Release" }

function setupTest(name, testfile)
    project(name)
    kind "ConsoleApp"
    language "C++"
	targetdir "bin/${cfg.buildcfg}"
	
	includedirs { "lib", "vendor", "%{prj.name}/vendor/spdlog/include", }

	files { "lib/**.hpp", "lib/**.cpp", "vendor/linalg/linalg.h",
            "test/testSynapse.hpp", testfile }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		optimize "On"
end
	
setupTest("NeuronTest", "test/testNeuron.cpp")
setupTest("LayerTest", "test/testLayer.cpp")
setupTest("ActivationsTest", "test/testActivations.cpp")
