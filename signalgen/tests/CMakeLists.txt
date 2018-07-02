# Include signalgen headers
include_directories(${SIGNALGEN_SOURCE_DIR}/include)

# Set up Boost
set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

# Run through each test file
file(GLOB TEST_SRCS RELATIVE ${SIGNALGEN_SOURCE_DIR}/tests *.cpp)
foreach(testSrc ${TEST_SRCS})
        # Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${testSrc} NAME_WE)

        add_executable(${testName} ${testSrc})

        # Link to Boost libraries targets and other dependencies
        target_link_libraries(${testName} ${Boost_LIBRARIES} signalgen)

        # Add test
        add_test(NAME ${testName} COMMAND ${testName})
endforeach(testSrc)