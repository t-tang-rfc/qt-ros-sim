/**
 * @file: robot_controller_delegate.cpp
 * 
 * @brief: Implementation of RobotControllerDelegate class
 * 
 * @date:
 * - created on 2025-05-26
 * - updated on 2025-05-28
 **/

#include "robot_controller_delegate.hpp"

namespace rf {

RobotControllerDelegate::RobotControllerDelegate(QObject *parent)
	: QObject(parent)
	, m_posX(-100)
	, m_posY(100)
	, m_posZ(-100)
	, m_rotX(0)
	, m_rotY(0)
	, m_rotZ(0)
{
	// Initialize with the same default values as in QML
}

qreal RobotControllerDelegate::posX() const { return m_posX; }
qreal RobotControllerDelegate::posY() const { return m_posY; }
qreal RobotControllerDelegate::posZ() const { return m_posZ; }
qreal RobotControllerDelegate::rotX() const { return m_rotX; }
qreal RobotControllerDelegate::rotY() const { return m_rotY; }
qreal RobotControllerDelegate::rotZ() const { return m_rotZ; }

void RobotControllerDelegate::setPosX(qreal x)
{
	if (!qFuzzyCompare(m_posX, x)) {
		m_posX = x;
		emit posXChanged();
	}
}

void RobotControllerDelegate::setPosY(qreal y)
{
	if (!qFuzzyCompare(m_posY, y)) {
		m_posY = y;
		emit posYChanged();
	}
}

void RobotControllerDelegate::setPosZ(qreal z)
{
	if (!qFuzzyCompare(m_posZ, z)) {
		m_posZ = z;
		emit posZChanged();
	}
}

void RobotControllerDelegate::setRotX(qreal x)
{
	if (!qFuzzyCompare(m_rotX, x)) {
		m_rotX = x;
		emit rotXChanged();
	}
}

void RobotControllerDelegate::setRotY(qreal y)
{
	if (!qFuzzyCompare(m_rotY, y)) {
		m_rotY = y;
		emit rotYChanged();
	}
}

void RobotControllerDelegate::setRotZ(qreal z)
{
	if (!qFuzzyCompare(m_rotZ, z)) {
		m_rotZ = z;
		emit rotZChanged();
	}
}

void RobotControllerDelegate::reset()
{
	setPosX(-100);
	setPosY(100);
	setPosZ(-100);
	setRotX(0);
	setRotY(0);
	setRotZ(0);
}

} // namespace rf
