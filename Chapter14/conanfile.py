from conan import ConanFile

class Pkg(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    generators = "CMakeDeps"
    default_options = {"libcoro/*:with_networking": False}

    def requirements(self):
        self.requires("benchmark/1.9.1")
        self.requires("nanobench/4.3.11")
        self.requires("doctest/2.4.11")
        self.requires("catch2/3.8.0")
        self.requires("libcoro/0.12.1")  # requires Linux
        self.requires("boost/1.86.0")
        if not self.settings.os == "Windows":
            self.requires("coost/3.0.2")  # const char to PCHAR on Windows

    def build_requirements(self):
        pass
