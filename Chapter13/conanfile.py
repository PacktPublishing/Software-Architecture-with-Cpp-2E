from conan import ConanFile

class Pkg(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    generators = "CMakeDeps"
    default_options = {"tracy/*:no_exit": True, "libcoro/*:with_networking": False}

    def requirements(self):
        self.requires("benchmark/1.9.4")
        self.requires("nanobench/4.3.11")
        self.requires("doctest/2.4.12")
        self.requires("catch2/3.11.0")
        self.requires("tracy/0.13.1")
        # requires Linux for networking
        self.requires("libcoro/0.15.0")
        self.requires("boost/1.89.0")
        if not self.settings.os == "Windows":
            self.requires("coost/3.0.2")  # const char to PCHAR on Windows

    def build_requirements(self):
        pass
