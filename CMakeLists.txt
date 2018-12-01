cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(LearnOpenGL LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(ThirdPartyLocations)
include(CompileOptionsTarget)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(HEADER_DIR ${CMAKE_SOURCE_DIR}/include/ogl)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(PRIVATE_DIR ${SRC_DIR}/private)

add_library(ogl
	${HEADER_DIR}/RenderWindow.h

	${PRIVATE_DIR}/RenderContext.h

	${SRC_DIR}/RenderContext.cpp
	${SRC_DIR}/RenderWindow.cpp
)

find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(ogl
	PRIVATE
		glad::glad

		glfw

		logl_CompileOptions
)

target_include_directories(ogl
	PUBLIC
		${CMAKE_SOURCE_DIR}/include
	PRIVATE
		${CMAKE_SOURCE_DIR}/src
)

option(OGL_BUILD_EXAMPLES "Build the example executables for Learn OpenGL" OFF)
if (OGL_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()
