from conan import ConanFile

class Pkg(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    generators = "CMakeDeps"
    default_options = {"aws-sdk-cpp/*:text-to-speech": False}

    def requirements(self):
        self.requires("spdlog/1.16.0")
        if not self.settings.os == "Windows":
            self.requires("aws-sdk-cpp/1.11.619")

    def build_requirements(self):
        pass
