from conan import ConanFile

class Pkg(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    generators = "CMakeDeps"

    def requirements(self):
        self.requires("spdlog/1.15.0")
        if not self.settings.os == "Windows":
            self.requires("aws-sdk-cpp/1.11.352")

    def build_requirements(self):
        pass
