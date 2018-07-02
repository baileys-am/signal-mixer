# Find source files
file(GLOB SOURCES ${SIGNALGEN_SOURCE_DIR}/src/*.cpp)

# Include headers and create a library called "signalgen"
include_directories(${SIGNALGEN_SOURCE_DIR}/include)
add_library(signalgen STATIC ${SOURCES})

# Make sure the compiler can find include files for library
# when other libraries or executables link to it
target_include_directories(signalgen PUBLIC ${SIGNALGEN_SOURCE_DIR}/include)