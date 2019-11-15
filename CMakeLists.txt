cmake_minimum_required(VERSION 2.6)
project(chickchirik-game-engine)

# Using modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${chickchirik-game-engine_SOURCE_DIR}/cmake")

# Set an output directory for our binaries
set(BIN_DIR ${chickchirik-game-engine_SOURCE_DIR}/bin)

# Set compilation flags based on compiler
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++14" )
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Set preprocessor definition MACROS
	# set project source path macro
add_compile_definitions(__SOURCEPATH__="${chickchirik-game-engine_SOURCE_DIR}/")
 	# set project config path macro
add_compile_definitions(__CONFIGPATH__="${chickchirik-game-engine_SOURCE_DIR}/configs/")
	# set project assets path macro
add_compile_definitions(__ASSETSPATH__="${chickchirik-game-engine_SOURCE_DIR}/assets/")

# Look up SDL2 and add the include directory to our include path
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

# Look up TMXLITE and add the include directory to our include path
find_package(TMXLITE REQUIRED)
include_directories(${TMXLITE_INCLUDE_DIR})

# Look up Boost C++ Libraries
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

# Set variables to hold paths to project directories
set(CORE_DIR ${chickchirik-game-engine_SOURCE_DIR}/core)
set(TEST_DIR ${chickchirik-game-engine_SOURCE_DIR}/tests)

# Look for all source files in core subproject and save them
file(GLOB_RECURSE CORESRC ${CORE_DIR}/*.cpp)
set(CORE_SOURCES ${CORESRC})

# Look in the subdirectories to find its CMakeLists.txt so we can build the executable
add_subdirectory(core)
add_subdirectory(tests)
