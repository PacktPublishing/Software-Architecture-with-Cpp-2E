from conan import ConanFile
from conan.tools.cmake import cmake_layout

class Pkg(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    generators = "CMakeDeps", "CMakeToolchain"
    default_options = {"drogon/*:with_boost": False, "drogon/*:with_orm": False, "drogon/*:with_ctl": True}

    def requirements(self):
        self.requires("drogon/1.9.12")
        self.requires("trantor/1.5.26")
        self.requires("inja/3.5.0")

    def build_requirements(self):
        self.tool_requires("drogon/<host_version>", options={"with_boost": False, "with_orm": False, "with_ctl": True})

    def layout(self):
        cmake_layout(self)
