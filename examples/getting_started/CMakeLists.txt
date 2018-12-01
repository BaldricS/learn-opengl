add_executable(HelloWindow
	${CMAKE_CURRENT_SOURCE_DIR}/hello_window.cpp
)

target_link_libraries(HelloWindow
	PRIVATE
		ogl
)
