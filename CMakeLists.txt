cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(LearnOpenGL LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(CompileOptionsTarget)
include(ResourceRegistration)
include(ThirdPartyLocations)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(HEADER_DIR ${CMAKE_SOURCE_DIR}/include/ogl)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(PRIVATE_DIR ${SRC_DIR}/private)

add_library(ogl
	${HEADER_DIR}/shaders/Program.h
	${HEADER_DIR}/shaders/SamplerUniform.h
	${HEADER_DIR}/shaders/Shader.h
	${HEADER_DIR}/shaders/ShaderType.h
	${HEADER_DIR}/shaders/UniformLocation.h

	${HEADER_DIR}/textures/Texture.h
	${HEADER_DIR}/textures/TextureMaxFilter.h
	${HEADER_DIR}/textures/TextureMinFilter.h
	${HEADER_DIR}/textures/TextureOptions.h
	${HEADER_DIR}/textures/TextureUnit.h
	${HEADER_DIR}/textures/TextureWrap.h

	${HEADER_DIR}/utils/MainMacro.h
	${HEADER_DIR}/utils/ProgramFactory.h
	${HEADER_DIR}/utils/ScopedBind.h
	${HEADER_DIR}/utils/TextureBuilder.h

	${HEADER_DIR}/Buffer.h
	${HEADER_DIR}/BufferType.h
	${HEADER_DIR}/BufferUsage.h
	${HEADER_DIR}/RenderWindow.h
	${HEADER_DIR}/VertexArray.h

	${PRIVATE_DIR}/ImageHandle.h
	${PRIVATE_DIR}/RenderContext.h

	${SRC_DIR}/shaders/Program.cpp
	${SRC_DIR}/shaders/SamplerUniform.cpp
	${SRC_DIR}/shaders/Shader.cpp
	${SRC_DIR}/shaders/UniformLocation.cpp

	${SRC_DIR}/textures/Texture.cpp
	${SRC_DIR}/textures/TextureUnit.cpp

	${SRC_DIR}/utils/ProgramFactory.cpp
	${SRC_DIR}/utils/TextureBuilder.cpp

	${SRC_DIR}/Buffer.cpp
	${SRC_DIR}/ImageHandle.cpp
	${SRC_DIR}/RenderContext.cpp
	${SRC_DIR}/RenderWindow.cpp
	${SRC_DIR}/VertexArray.cpp
)

find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(stb REQUIRED)

target_link_libraries(ogl
	PUBLIC
		glad::glad

		glm

	PRIVATE
		glfw

		ogl_CompileOptions

		stb::stb
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
