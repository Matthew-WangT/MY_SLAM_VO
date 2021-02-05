cmake_minimum_required(VERSION 3.10)
project(vo_0.1)
find_package(Eigen3 REQUIRED)
find_package(OpenCV 3.4 REQUIRED)
include_directories(
include
src
)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
#${OPenCV_LIBS}
        )