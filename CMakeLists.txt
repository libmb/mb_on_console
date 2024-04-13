cmake_minimum_required(VERSION 3.12)

project(mb_on_console)

file(GLOB_RECURSE SOURCES "src/*.c" "src/**/*.c")

add_executable(mb_on_console ${SOURCES})

target_include_directories(mb_on_console PRIVATE
    "submodules/core/include"
    "submodules/real_float/include"
)

if(WIN32)
    target_link_libraries(mb_on_console
        "${CMAKE_SOURCE_DIR}/submodules/core/mb_core.lib"
        "${CMAKE_SOURCE_DIR}/submodules/real_float/mb_real_float.lib"
    )
else()
    target_link_libraries(mb_on_console
      "${CMAKE_SOURCE_DIR}/submodules/core/libmb_core.a"
      "${CMAKE_SOURCE_DIR}/submodules/real_float/libmb_real_float.a"
    )
endif()

set_target_properties(mb_on_console PROPERTIES
    OUTPUT_NAME "mb_on_console"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

foreach(CONFIG_TYPE IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER ${CONFIG_TYPE} CONFIG_TYPE_UPPER)
    set_target_properties(mb_on_console PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_TYPE_UPPER} "${CMAKE_SOURCE_DIR}"
        LIBRARY_OUTPUT_DIRECTORY_${CONFIG_TYPE_UPPER} "${CMAKE_SOURCE_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_${CONFIG_TYPE_UPPER} "${CMAKE_SOURCE_DIR}"
    )
endforeach()
