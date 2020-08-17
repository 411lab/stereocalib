cmake_minimum_required(VERSION 3.14)
project(stereocalib)

set(CMAKE_CXX_STANDARD 11)

# 寻找OpenCV库
find_package( OpenCV 3 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(calib calib.cpp)
add_executable(getImages getImages.cpp)
# 链接OpenCV库
target_link_libraries(calib ${OpenCV_LIBS})
target_link_libraries(getImages ${OpenCV_LIBS})