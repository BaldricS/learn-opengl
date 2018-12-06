function(CreateExample)
    set(SINGLE_OPTIONS MAIN)
    set(MULTI_OPTIONS LIBS TEXTURES)

    cmake_parse_arguments(EX "" "${SINGLE_OPTIONS}" "${MULTI_OPTIONS}" ${ARGN})

    add_executable(${EX_MAIN}
        ${CMAKE_CURRENT_SOURCE_DIR}/${EX_MAIN}.cpp
    )

    target_link_libraries(${EX_MAIN}
        PRIVATE
            ogl
            ogl_CompileOptions

            ${LIBS}
    )

    if (DEFINED EX_TEXTURES)
        TargetRegisterTextures(${EX_MAIN}
            TEXTURES
                ${EX_TEXTURES}
        )
    endif()
endfunction()

add_subdirectory(getting_started)