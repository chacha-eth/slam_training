cmake_minimum_required(VERSION 3.10)

project(features LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS "-D DEBUG -Wall -Wfatal-errors -Wextra -Wno-unused-variable")

##################### Eigen ######################
find_package(Eigen3 REQUIRED)
message(STATUS "Eigen Version: ${EIGEN3_VERSION_STRING} ${EIGEN3_VERSION}")

##################### OpenCV ######################
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV Version: ${OpenCV_VERSION}")

##################### Include Directory ######################
include_directories(include)

##################### Build one executable per .cpp ######################
file(GLOB SOURCES "*.cpp")

foreach(source_file IN LISTS SOURCES)
    get_filename_component(target_name ${source_file} NAME_WE)
    add_executable(${target_name} ${source_file})
    target_link_libraries(${target_name} ${OpenCV_LIBS} Eigen3::Eigen)
endforeach()
