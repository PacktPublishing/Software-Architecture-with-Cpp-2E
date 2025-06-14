from conan import ConanFile

class Pkg(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    generators = "CMakeDeps"
    default_options = {"tracy/*:no_exit": True, "libcoro/*:with_networking": False}

    def requirements(self):
        self.requires("benchmark/1.9.1")
        self.requires("nanobench/4.3.11")
        self.requires("doctest/2.4.11")
        self.requires("catch2/3.8.1")
        self.requires("tracy/0.11.0")
        self.requires("libcoro/0.14.1")  # requires Linux
        self.requires("boost/1.88.0")
        if not self.settings.os == "Windows":
            self.requires("coost/3.0.2")  # const char to PCHAR on Windows

    def build_requirements(self):
        pass
