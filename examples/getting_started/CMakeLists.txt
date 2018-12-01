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