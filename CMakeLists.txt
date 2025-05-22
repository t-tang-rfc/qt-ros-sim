cmake_minimum_required(VERSION 3.16)
project(qt_ros_sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt installation path
set(Qt6_DIR "/opt/homebrew/Cellar/qt/6.8.2/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(src)

add_executable(qt_ros_sim
	src/main.cpp
	src/main_window.cpp
)

target_link_libraries(qt_ros_sim PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
