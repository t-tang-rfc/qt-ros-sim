cmake_minimum_required(VERSION 3.16)
project(qt_ros_sim LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# @note: adjust the path to your Qt installation, or use symbolic link if necessary
list(APPEND CMAKE_PREFIX_PATH "/opt/qt/qt6/gcc_64/lib/cmake")
find_package(Qt6 COMPONENTS Core Gui Quick REQUIRED)

qt_standard_project_setup(REQUIRES 6.8)

set(QT_QML_GENERATE_QMLLS_INI ON)

qt_add_resources(QML_RESOURCES qml/qml.qrc)

add_executable(qt_ros_sim
	src/main.cpp
	# src/main_window.cpp
	src/display_widget.cpp
	src/robot_controller_delegate.cpp
	${QML_RESOURCES}
)

target_link_libraries(qt_ros_sim PRIVATE Qt6::Core Qt6::Gui Qt6::Quick)

# qt_add_qml_module(qt_ros_sim
# 	URI rf
# 	VERSION 1.0
# 	QML_FILES
# 		qml/Display.qml
# 	RESOURCES
# 		qml/qml.qrc
# 	SOURCES
# 		src/robot_controller_delegate.cpp
# 		src/robot_controller_delegate.hpp
# )
