from conan import ConanFile

class Pkg(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    generators = "CMakeDeps"
    default_options = {"aws-sdk-cpp/*:text-to-speech": False}

    def requirements(self):
        self.requires("spdlog/1.17.0")
        self.requires("aws-sdk-cpp/1.11.692")

    def build_requirements(self):
        pass
