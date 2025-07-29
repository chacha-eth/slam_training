# set minimum required version for cmake
cmake_minimum_required(VERSION 3.10)

# define the project name
set(project_name "slam_training")

# set the project name
project("${project_name}")

# this is a C++14 project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "-D DEBUG -Wall -Wfatal-errors -Wextra -Wno-unused-variable")


#  add opencv package to the project 
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(OpenCV_LIBRARIES ${OpenCV_LIBS})
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
# message(STATUS "    libraries: ${OpenCV_LIBS}")



# add lab directories
# add_subdirectory(lab1)
add_subdirectory(lab2)
# add_subdirectory(lab3)
# add_subdirectory(lab4)
# add_subdirectory(lab5)

