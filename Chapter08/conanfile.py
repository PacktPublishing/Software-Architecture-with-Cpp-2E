from conan import ConanFile
from conan.tools.build import can_run
from conan.tools.cmake import cmake_layout, CMake, CMakeDeps, CMakeToolchain

class CustomerConan(ConanFile):
    name = "customer"
    version = "0.0.1"
    license = "MIT"
    author = "Authors"
    homepage = "https://example.com"
    url = "https://github.com/PacktPublishing/Software-Architecture-with-Cpp-2E"
    description = "Library and app for the Customer microservice"
    topics = ("Customer", "tradefair")
    settings = "os", "compiler", "build_type", "arch"
    default_options = {"drogon/*:with_boost": "False", "drogon/*:with_orm": "False"}

    exports_sources = "CMakeLists.txt", "LICENSE", "README.md", "cmake/*", "include/*", "src/*", "test/*"

    def requirements(self):
        self.requires("drogon/1.9.9")

    def build_requirements(self):
        self.test_requires("gtest/1.15.0")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if can_run(self):
            cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["customer"]
