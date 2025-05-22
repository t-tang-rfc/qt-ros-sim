/**
 * @file: main_window.hpp
 * 
 * @brief: GUI main window
 * 
 * @details:
 * The GUI mainwindow contains:
 * - a display widget
 * 
 * @date:
 * - created on 2025-05-22
 * - updated on 2025-05-22
 **/

#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QWidget>

namespace rf
{

	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget* parent = nullptr);
		~MainWindow();

	private:
		void setupUi();
	};
}

#endif // MAIN_WINDOW_HPP
