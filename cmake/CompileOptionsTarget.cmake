include_guard(GLOBAL)

add_library(ogl_CompileOptions INTERFACE)

target_compile_options(ogl_CompileOptions
	INTERFACE
		/W4 /WX /MP
)
