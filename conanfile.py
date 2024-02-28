from conan import ConanFile

class Example(ConanFile):
    name = "Example"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain", "VirtualBuildEnv", "VirtualRunEnv"
    default_options = {
        "boost/*:without_test": True,
        "sqlite3/*:threadsafe": 2
    }
    requires = [("boost/1.82.0")]
    
