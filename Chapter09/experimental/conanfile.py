from conan import ConanFile
from conan.tools.build import can_run
from conan.tools.cmake import cmake_layout, CMake, CMakeDeps, CMakeToolchain

class StoresConan(ConanFile):
    name = "stores"
    version = "0.0.4"
    license = "MIT"
    author = "Authors"
    homepage = "https://example.com"
    url = "https://github.com/PacktPublishing/Software-Architecture-with-Cpp-2E"
    description = "Library and app"
    topics = ("Stores", "stores")
    settings = "os", "compiler", "build_type", "arch"

    exports_sources = "CMakeLists.txt", "LICENSE", "README.md", "cmake/*", "include/*", "src/*"

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

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["stores"]
