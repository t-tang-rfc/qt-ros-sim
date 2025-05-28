/**
 * @file: display_widget.cpp
 * 
 * @brief: implementation of the DisplayWidget class
 * 
 * @author:
 * - madpang
 * - t-tang-rfc
 * 
 * @date:
 * - created on 2025-05-22
 * - updated on 2025-05-26
 **/

#include "display_widget.hpp"

#include <QQmlContext>

#include "robot_controller_delegate.hpp"

namespace {

const qreal KBD_MOVE_STEP = 5.0; // Default movement step size via keyboard control

} // namespace

namespace rf {

DisplayWidget::DisplayWidget(QWidget* parent)
	: QQuickWidget(parent)
	, robot_pose(6, 0) // Initialize with 6 elements set to 0
{
	setResizeMode(QQuickWidget::SizeRootObjectToView);

	// Create RobotControllerDelegate as a child
	auto controller_delegate = new RobotControllerDelegate(this);
	// Set initial pose values
	robot_pose = {controller_delegate->posX(), controller_delegate->posY(),
		controller_delegate->posZ(), controller_delegate->rotX(),
		controller_delegate->rotY(), controller_delegate->rotZ()};

	// Expose to QML as 'controller'
	rootContext()->setContextProperty(QStringLiteral("controller"), controller_delegate);

	// Set the QML source file
	setSource(QUrl("qrc:/qml/Display.qml"));

	// Connect signals to controller slots
	connect(this, &DisplayWidget::setPosX, controller_delegate, &RobotControllerDelegate::setPosX);
	connect(this, &DisplayWidget::setPosY, controller_delegate, &RobotControllerDelegate::setPosY);
	connect(this, &DisplayWidget::setPosZ, controller_delegate, &RobotControllerDelegate::setPosZ);	
}

DisplayWidget::~DisplayWidget() = default;

void DisplayWidget::keyPressEvent(QKeyEvent* event)
{
	switch (event->key()) {
		case Qt::Key_W:
			moveX(KBD_MOVE_STEP);
			break;
		case Qt::Key_S:
			moveX(-KBD_MOVE_STEP);
			break;
		case Qt::Key_A:
			moveZ(-KBD_MOVE_STEP);
			break;
		case Qt::Key_D:
			moveZ(KBD_MOVE_STEP);
			break;
		case Qt::Key_Up:
			moveY(KBD_MOVE_STEP);
			break;
		case Qt::Key_Down:
			moveY(-KBD_MOVE_STEP);
			break;
		default:
			QQuickWidget::keyPressEvent(event);
			break;
	}
}

void DisplayWidget::moveX(qreal delta_x)
{
	robot_pose[0] += delta_x;
	emit setPosX(robot_pose[0]);
}

void DisplayWidget::moveY(qreal delta_y)
{
	robot_pose[1] += delta_y;
	emit setPosY(robot_pose[1]);
}

void DisplayWidget::moveZ(qreal delta_z)
{
	robot_pose[2] += delta_z;
	emit setPosZ(robot_pose[2]);
}

} // namespace rf
