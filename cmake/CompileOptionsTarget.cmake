add_library(ogl_CompileOptions INTERFACE)

if (MSVC)
	list(APPEND COMPILER_FLAGS /W4 /WX)

	if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
		list(APPEND COMPILER_FLAGS
			/MP
			/experimental:external /external:W0 /external:anglebrackets
		)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES Clang)
		list(APPEND COMPILER_FLAGS
			"SHELL:-Xclang --system-header-prefix=glad/"
			"SHELL:-Xclang --system-header-prefix=glfw/"
			"SHELL:-Xclang --system-header-prefix=glm/"
			"SHELL:-Xclang --system-header-prefix=stb/"
		)
	endif()
elseif(CLANG)
	set(COMPILER_FLAGS
		--system-header-prefix=glad/
		--system-header-prefix=glfw/
		--system-header-prefix=glm/
		--system-header-prefix=stb/
	)
endif()

target_compile_options(ogl_CompileOptions
	INTERFACE
		${COMPILER_FLAGS}
)
