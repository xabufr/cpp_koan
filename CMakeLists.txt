cmake_minimum_required (VERSION 2.8)
project (bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")
aux_source_directory(. SRC_LIST)
include_directories(lib)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

SET(source_files
    src/main.cpp
    #Add sources here
    src/00intro.cpp
    src/01class.cpp
    src/02polymorphism.cpp
    src/03templates.cpp
    src/04variadic_templates.cpp
    src/05static_assert.cpp
    src/06references.cpp
    src/07move.cpp
    src/08smart_ptr.cpp
    src/09containers.cpp
    src/10algorithm.cpp
    )

add_executable(${PROJECT_NAME} ${SRC_LIST} ${source_files} )
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

