cmake_minimum_required(VERSION 3.16)
project(qt_ros_sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt installation path
set(Qt6_DIR "/opt/homebrew/Cellar/qt/6.8.2/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS Core Gui Widgets Quick QuickWidgets REQUIRED)

include_directories(src)

qt_add_resources(QML_RESOURCES qml/qml.qrc)

add_executable(qt_ros_sim
    src/main.cpp
    src/main_window.cpp
    src/display_widget.cpp
    ${QML_RESOURCES}
)

target_link_libraries(qt_ros_sim PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Quick Qt6::QuickWidgets)
