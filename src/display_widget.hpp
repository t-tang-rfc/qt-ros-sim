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
#include <QtGlobal>
#include <QList>

namespace rf {

class DisplayWidget : public QQuickWidget
{
	Q_OBJECT

	public:
		explicit DisplayWidget(QWidget* parent = nullptr);
		~DisplayWidget();

	/// @note: the following parts implements a simple robot controller using keyboard input

		Q_SLOT void moveX(qreal delta_x);
		Q_SLOT void moveY(qreal delta_y);
		Q_SLOT void moveZ(qreal delta_z);

		Q_SIGNAL void setPose(const QList<qreal>& pose);

	protected:
		void keyPressEvent(QKeyEvent* event) override;

	private:
		QList<qreal> robot_pose_; // a 6-element list for robot pose tracking

	/// <<<
};

} // namespace rf

#endif // DISPLAY_WIDGET_HPP
