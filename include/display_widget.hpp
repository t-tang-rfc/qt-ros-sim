/**
 * @file: display_widget.hpp
 * 
 * @brief: A widget class for displaying the 3D scene with the robot
 * 
 * @author: madpang
 *
 * @date:
 * - created on 2025-05-22
 * - updated on 2025-05-28
 **/

#ifndef DISPLAY_WIDGET_HPP
#define DISPLAY_WIDGET_HPP

#include <QQuickWidget>

#include "robot_controller_delegate.hpp"

namespace rf {

class DisplayWidget : public QQuickWidget
{
	Q_OBJECT
public:
	explicit DisplayWidget(QWidget* parent = nullptr);
	~DisplayWidget();

	private:
		RobotControllerDelegate* m_robotController = nullptr;
};

} // namespace rf

#endif // DISPLAY_WIDGET_HPP