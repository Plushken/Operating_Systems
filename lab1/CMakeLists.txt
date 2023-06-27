cmake_minimum_required(VERSION 3.21)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(INC_DIR /opt/homebrew/Cellar/boost/1.82.0_1/include)
set(LINK_DIR /opt/homebrew/Cellar/boost/1.82.0_1/lib)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(boost)


find_package(Boost 1.81.0 REQUIRED COMPONENTS filesystem system)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(main main.cpp)
add_dependencies(main reporter creator)
target_link_libraries(main ${Boost_LIBRARIES})

add_executable(creator creator.cpp employee.h)
target_link_libraries(creator ${Boost_LIBRARIES})

add_executable(reporter reporter.cpp employee.h)
target_link_libraries(reporter ${Boost_LIBRARIES})

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove main
        COMMAND ${CMAKE_COMMAND} -E remove creator
        COMMAND ${CMAKE_COMMAND} -E remove reporter
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/binFile/Users/radikravinsky/Desktops/*
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/reports/*
        )
