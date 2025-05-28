/**
 * @file: display_widget.cpp
 * 
 * @brief: implementation of the DisplayWidget class
 * 
 * @date:
 * - created on 2025-05-22
 * - updated on 2025-05-26
 **/

#include "display_widget.hpp"

#include <QQmlContext>

#include "robot_controller_delegate.hpp"

namespace rf {

DisplayWidget::DisplayWidget(QWidget* parent)
: QQuickWidget(parent)
{
	setResizeMode(QQuickWidget::SizeRootObjectToView);

	// Create RobotControllerDelegate as a child
	auto controller_delegate = new RobotControllerDelegate(this);

	// Expose to QML as 'controller'
	rootContext()->setContextProperty(QStringLiteral("controller"), controller_delegate);

	setSource(QUrl("qrc:/qml/Display.qml"));
}

DisplayWidget::~DisplayWidget() = default;

} // namespace rf
