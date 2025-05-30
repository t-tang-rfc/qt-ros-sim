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
const int WINDOW_WIDTH = 1440; // Default width of the display window
const int WINDOW_HEIGHT = 810; // Default height of the display window

} // namespace

namespace rf {

DisplayWidget::DisplayWidget(QWindow* parent)
	: QQuickView(parent)
	, robot_pose_(6, 0) // Initialize with 6 elements set to 0
{
	setTitle("Display Main Window");
	setWidth(WINDOW_WIDTH);
	setHeight(WINDOW_HEIGHT);
	setResizeMode(QQuickView::SizeRootObjectToView);
	
	// Load the module defined by `qt_add_qml_module` in CMakeLists.txt
	loadFromModule("RobotSimulator", "Display");
	
	// Create RobotControllerDelegate as a child
	// auto controller_delegate = new RobotControllerDelegate(this);
	// Set initial pose values
	// robot_pose_ = controller_delegate->getPose();

	/// @todo: Expose to QML as 'controller'
	// setInitialProperties({{"controller", controller_delegate}});
	// rootContext()->setContextProperty(QStringLiteral("controller"), controller_delegate);

	// Connect signals to controller slots
	// connect(this, &DisplayWidget::setPose, controller_delegate, &RobotControllerDelegate::setPose);
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
			QQuickView::keyPressEvent(event);
			break;
	}
}

void DisplayWidget::moveX(qreal delta_x)
{
	robot_pose_[0] += delta_x;
	emit setPose(robot_pose_);
}

void DisplayWidget::moveY(qreal delta_y)
{
	robot_pose_[1] += delta_y;
	emit setPose(robot_pose_);
}

void DisplayWidget::moveZ(qreal delta_z)
{
	robot_pose_[2] += delta_z;
	emit setPose(robot_pose_);
}

} // namespace rf
