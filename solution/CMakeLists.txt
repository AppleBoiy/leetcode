cmake_minimum_required(VERSION 3.10)

project(leetcode-solution)

set(CMAKE_CXX_STANDARD 17)

file(GLOB TOP_LEVEL_ITEMS "${CMAKE_SOURCE_DIR}/*")

foreach (first ${TOP_LEVEL_ITEMS})
    file(GLOB SECOND_LEVEL_ITEMS "${first}/*")
    foreach (item ${SECOND_LEVEL_ITEMS})
        if (IS_DIRECTORY ${item})
            get_filename_component(dir_name ${item} NAME)
            if (EXISTS "${item}/CMakeLists.txt")
                add_subdirectory(${item})
            endif ()
        endif ()
    endforeach ()
endforeach ()
