import os
from conan import ConanFile
from conan.tools.build import can_run
from conan.tools.cmake import CMake, cmake_layout, CMakeDeps, CMakeToolchain

class StoresTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"

    def requirements(self):
        self.requires(self.tested_reference_str)

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self, generator="Ninja")
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        if can_run(self):
            cmd = os.path.join(self.build_folder, "example")
            self.run(cmd, env="conanrun")
