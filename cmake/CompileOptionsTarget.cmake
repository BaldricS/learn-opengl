include_guard(GLOBAL)

add_library(logl_CompileOptions INTERFACE)

target_compile_options(logl_CompileOptions
	INTERFACE
		/W4 /WX /MP
)
