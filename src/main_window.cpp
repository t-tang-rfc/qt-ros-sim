/**
 * @file: main_window.cpp
 * 
 * @brief: implementation of the GUI main window
 * 
 * @date:
 * - created on 2025-05-22
 * - updated on 2025-05-22
 **/

#include "main_window.hpp"
#include "display_widget.hpp"
#include <QSize>

namespace
{
	const QSize MAIN_WINDOW_SIZE(1440, 810); // 16:9 aspect ratio
}

namespace rf {

MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
{
	setupUi();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUi()
{
	setFixedSize(MAIN_WINDOW_SIZE);
	setWindowTitle("Display Main Window");

	auto* display = new DisplayWidget(this);
	setCentralWidget(display);
}

} // namespace rf
