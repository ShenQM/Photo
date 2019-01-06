cmake_minimum_required(VERSION 3.13)
project(Photo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include_directories( ${OpenCV_INCLUDE_DIRS} )
find_package(OpenCV)

include_directories( ${Qt_INCLUDE_DIRS} )
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Quick REQUIRED)


add_executable(Photo main.cpp UI/MainWindow.cpp UI/MainWindow.h UI/ImageWidget.h UI/ImageWidget.cpp)

target_link_libraries( Photo ${OpenCV_LIBS} )

target_link_libraries(Photo Qt5::Widgets)
target_link_libraries(Photo Qt5::Core)
target_link_libraries(Photo Qt5::Quick)
