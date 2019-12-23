cmake_minimum_required(VERSION 2.9)
project(chickchirik-game-engine)

# Function recursively iterates through provided directories and creates a
# variable string with all directories where .h or .hpp files can be found.
# Big thanks to Gonzalo Garramuno (https://cmake.org/pipermail/cmake/2017-October/066495.html)
function(make_include_directories_list RESULT_VAR)
	if((ARGC EQUAL 3) OR (ARGC GREATER 3))
		foreach(dir IN LISTS ARGN)
			file(GLOB_RECURSE new_list ${dir}/*.h ${dir}/*.hpp)
			set(dir_list "")
			foreach(file_path ${new_list})
				get_filename_component(dir_path ${file_path} PATH)
				set(dir_list ${dir_list} ${dir_path})
			endforeach()
			list(REMOVE_DUPLICATES dir_list)
			list(APPEND RESULT_LIST ${dir_list})
		endforeach()
		set(${RESULT_VAR} ${RESULT_LIST} PARENT_SCOPE)
	else()
		message("wrong function usage: make_include_directories_list recuires at least two arguments, first of which is a return varibale.")
	endif()
endfunction()

# Set root directory alias
set(ROOT_DIR "${chickchirik-game-engine_SOURCE_DIR}")

# Set an output directory for our binaries
set(BIN_DIR ${ROOT_DIR}/bin)

# Set variables to hold paths to project directories
set(CORE_DIR ${ROOT_DIR}/core)
set(TESTS_DIR ${ROOT_DIR}/tests)
set(DEP_DIR ${ROOT_DIR}/dependencies)

# Set preprocessor definition MACROS
	# set project source path macro
add_compile_definitions(__SOURCEPATH__="${ROOT_DIR}/")
 	# set project config path macro
add_compile_definitions(__CONFIGPATH__="${ROOT_DIR}/configs/")
	# set project assets path macro
add_compile_definitions(__ASSETSPATH__="${ROOT_DIR}/assets/")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Look up Boost C++ Libraries
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

# Find SDL2 and OpenGL
find_package(SDL2 REQUIRED COMPONENTS main)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Look for all source files in core subproject and save them
file(GLOB_RECURSE CORE_CPP ${CORE_DIR}/*.cpp ${CORE_DIR}/*.c)

# Look for all source files in tests subproject and save them
file(GLOB_RECURSE TESTS_CPP ${TESTS_DIR}/*.cpp ${TESTS_DIR}/*.c)

# Look for all include paths in core, tests and Dependencies and include them
make_include_directories_list(INCLUDE_LIST ${CORE_DIR} ${TEST_DIR} ${ROOT_DIR}/Dependencies)
include_directories(${INCLUDE_LIST})

# Set compilation flags based on compiler
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++14")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
	# Look for all dynamic libraries in dependencies and save them in the list
	# file(GLOB_RECURSE DEP_LIBS ${DEP_DIR}/*.dylib)
	# link_directories(${ROOT_DIR}/dependencies/sdl2/SDL2-2.0.10-macOS)
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	# file(GLOB_RECURSE DEP_LIBS ${DEP_DIR}/*.dll)
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Look in the subdirectories to find its CMakeLists.txt so we can build the executable
add_subdirectory(core)
add_subdirectory(tests)
