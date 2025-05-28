/**
 * @file: display_widget.hpp
 * 
 * @brief: A widget class for displaying the 3D scene with the robot
 * 
 * @author:
 * - madpang
 * - t-tang-rfc
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

	signals:
		void setPosX(qreal x);
		void setPosY(qreal y);
		void setPosZ(qreal z);

	protected:
		void keyPressEvent(QKeyEvent* event) override;

	private:
		RobotControllerDelegate* m_controller = nullptr;
		const qreal m_moveStep = 5.0;
};

} // namespace rf

#endif // DISPLAY_WIDGET_HPP
