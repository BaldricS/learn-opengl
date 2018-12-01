cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(LearnOpenGL)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(ThirdPartyLocations)
include(CompileOptionsTarget)

add_library(logl
)

target_link_libraries(logl
	PRIVATE
		logl::CompileOptions
)

target_include_directories(logl
	PUBLIC
		${CMAKE_SOURCE_DIR}/include
	PRIVATE
		${CMAKE_SOURCE_DIR}/src
)

option(LOGL_BUILD_EXAMPLES "Build the example executables for Learn OpenGL" OFF)
if (LOGL_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()
