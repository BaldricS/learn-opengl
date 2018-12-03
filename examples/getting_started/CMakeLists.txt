add_executable(HelloWindow
	${CMAKE_CURRENT_SOURCE_DIR}/hello_window.cpp
)

target_link_libraries(HelloWindow
	PRIVATE
		ogl
		ogl_CompileOptions
)

add_executable(HelloTriangle
	${CMAKE_CURRENT_SOURCE_DIR}/hello_triangle.cpp
)

target_link_libraries(HelloTriangle
	PRIVATE
		glad::glad
		
		ogl
		ogl_CompileOptions
)

add_executable(HelloTriangle_01
	${CMAKE_CURRENT_SOURCE_DIR}/hello_triangle_01.cpp
)

target_link_libraries(HelloTriangle_01
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

add_executable(HelloTriangle_02
	${CMAKE_CURRENT_SOURCE_DIR}/hello_triangle_02.cpp
)

target_link_libraries(HelloTriangle_02
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

add_executable(HelloTriangle_03
	${CMAKE_CURRENT_SOURCE_DIR}/hello_triangle_03.cpp
)

target_link_libraries(HelloTriangle_03
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

add_executable(Shaders
	${CMAKE_CURRENT_SOURCE_DIR}/shaders.cpp
)

target_link_libraries(Shaders
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

add_executable(Shaders_01
	${CMAKE_CURRENT_SOURCE_DIR}/shaders_01.cpp
)

target_link_libraries(Shaders_01
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

add_executable(Shaders_02
	${CMAKE_CURRENT_SOURCE_DIR}/shaders_02.cpp
)

target_link_libraries(Shaders_02
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

add_executable(Shaders_03
	${CMAKE_CURRENT_SOURCE_DIR}/shaders_03.cpp
)

target_link_libraries(Shaders_03
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

add_executable(Textures
	${CMAKE_CURRENT_SOURCE_DIR}/textures.cpp
)

target_link_libraries(Textures
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

TargetRegisterTextures(Textures
	TEXTURES
		awesomeface.png
		container.jpg
)

add_executable(Textures_01
	${CMAKE_CURRENT_SOURCE_DIR}/textures_01.cpp
)

target_link_libraries(Textures_01
	PRIVATE
		glad::glad

		ogl
		ogl_CompileOptions
)

TargetRegisterTextures(Textures_01
	TEXTURES
		awesomeface.png
		container.jpg
)

add_executable(Transformations
	${CMAKE_CURRENT_SOURCE_DIR}/transformations.cpp
)

target_link_libraries(Transformations
	PRIVATE
		glad::glad

		glm

		ogl
		ogl_CompileOptions
)

TargetRegisterTextures(Transformations
	TEXTURES
		awesomeface.png
		container.jpg
)

add_executable(Transformations_01
	${CMAKE_CURRENT_SOURCE_DIR}/transformations_01.cpp
)

target_link_libraries(Transformations_01
	PRIVATE
		glad::glad

		glm

		ogl
		ogl_CompileOptions
)

TargetRegisterTextures(Transformations_01
	TEXTURES
		awesomeface.png
		container.jpg
)