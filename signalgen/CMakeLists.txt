# CMakeLists files in this project can refer to the root source directory
# of the project as ${SIGNALGEN_SOURCE_DIR} and to the root binary directory.
cmake_minimum_required(VERSION 3.5.1)
project(SIGNALGEN)

# Recurse into the "src" subdirectory This does not actually cause another
# cmake executable to run. The same process will walk through the project's
# entire directory structure.
add_subdirectory(src)

# Enable testing and recurse into the "tests" subdirectory.
enable_testing()
add_subdirectory(tests)
