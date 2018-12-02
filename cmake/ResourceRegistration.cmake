set(__resource_dir ${CMAKE_SOURCE_DIR}/resources)
set(__texture_dir ${__resource_dir}/textures)

function(TargetRegisterTextures TAR)
    set(multiValueArgs TEXTURES)
    cmake_parse_arguments(REG "" "" "${multiValueArgs}" ${ARGN})

    list(LENGTH REG_TEXTURES TEXTURE_LENGTH)

    if (TEXTURE_LENGTH EQUAL 0)
        return()
    endif()

    foreach(TEX IN LISTS REG_TEXTURES)
        list(APPEND TEX_PATHS ${__texture_dir}/${TEX})
    endforeach()

    set(OUTPUT_DIR $<TARGET_FILE_DIR:${TAR}>/resources/textures)
    add_custom_command(TARGET ${TAR} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TEX_PATHS} ${OUTPUT_DIR}
    )
endfunction()