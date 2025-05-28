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

namespace rf {

DisplayWidget::DisplayWidget(QWidget* parent)
: QQuickWidget(parent)
{
	setResizeMode(QQuickWidget::SizeRootObjectToView);

	// Create RobotControllerDelegate as a child
	m_robotController = new RobotControllerDelegate(this);

	// Expose to QML as 'robotController'
	rootContext()->setContextProperty(QStringLiteral("robotController"), m_robotController);

	setSource(QUrl("qrc:/qml/Display.qml"));
}

DisplayWidget::~DisplayWidget() = default;

} // namespace rf
