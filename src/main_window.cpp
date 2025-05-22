#include "main_window.hpp"
#include <QWidget>

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
	// Optionally set window title or other properties here
	setWindowTitle("Empty Main Window");
}

} // namespace rf
