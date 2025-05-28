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

namespace rf {

DisplayWidget::DisplayWidget(QWidget* parent)
: QQuickWidget(parent)
{
	setResizeMode(QQuickWidget::SizeRootObjectToView);

	// Create RobotControllerDelegate as a child
	m_controller = new RobotControllerDelegate(this);

	// Expose to QML as 'controller'
	rootContext()->setContextProperty(QStringLiteral("controller"), m_controller);

	// Connect signals to controller slots
	connect(this, &DisplayWidget::setPosX, m_controller, &RobotControllerDelegate::setPosX);
	connect(this, &DisplayWidget::setPosY, m_controller, &RobotControllerDelegate::setPosY);
	connect(this, &DisplayWidget::setPosZ, m_controller, &RobotControllerDelegate::setPosZ);

	setSource(QUrl("qrc:/qml/Display.qml"));
}

DisplayWidget::~DisplayWidget() = default;

void DisplayWidget::keyPressEvent(QKeyEvent* event)
{
	qreal x = m_controller->posX();
	qreal y = m_controller->posY();
	qreal z = m_controller->posZ();

	switch (event->key()) {
		case Qt::Key_W:
			x += m_moveStep;
			emit setPosX(x);
			break;
		case Qt::Key_S:
			x -= m_moveStep;
			emit setPosX(x);
			break;
		case Qt::Key_A:
			z -= m_moveStep;
			emit setPosZ(z);
			break;
		case Qt::Key_D:
			z += m_moveStep;
			emit setPosZ(z);
			break;
		case Qt::Key_Up:
			y += m_moveStep;
			emit setPosY(y);
			break;
		case Qt::Key_Down:
			y -= m_moveStep;
			emit setPosY(y);
			break;
		default:
			QQuickWidget::keyPressEvent(event);
			break;
	}
}

} // namespace rf
