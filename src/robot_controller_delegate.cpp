/**
 * @file: robot_controller_delegate.cpp
 * 
 * @brief: Implementation of RobotControllerDelegate class
 * 
 * @author:
 * - madpang
 * - t-tang-rfc
 * 
 * @date:
 * - created on 2025-05-26
 * - updated on 2025-05-28
 **/

#include "robot_controller_delegate.hpp"

#include <QList>

namespace rf {

const QList<qreal> DEFAULT_POSE = { -100, 100, -100, 0, 0, 0 };

}

namespace rf {

RobotControllerDelegate::RobotControllerDelegate(QObject *parent)
	: QObject(parent)
	, m_posX(DEFAULT_POSE[0])
	, m_posY(DEFAULT_POSE[1])
	, m_posZ(DEFAULT_POSE[2])
	, m_rotX(DEFAULT_POSE[3])
	, m_rotY(DEFAULT_POSE[4])
	, m_rotZ(DEFAULT_POSE[5])
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
	setPosX(DEFAULT_POSE[0]);
	setPosY(DEFAULT_POSE[1]);
	setPosZ(DEFAULT_POSE[2]);
	setRotX(DEFAULT_POSE[3]);
	setRotY(DEFAULT_POSE[4]);
	setRotZ(DEFAULT_POSE[5]);
}

} // namespace rf
