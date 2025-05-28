/**
 * @file: robot_controller_delegate.hpp
 * 
 * @brief: A controller delegate class for the robot in the 3D scene
 * 
 * @author:
 * - madpang
 * - t-tang-rfc
 *
 * @date:
 * - created on 2025-05-26
 * - updated on 2025-05-28
 **/

#ifndef ROBOT_CONTROLLER_DELEGATE_HPP
#define ROBOT_CONTROLLER_DELEGATE_HPP

#include <QObject>
#include <QtGlobal>

namespace rf {

class RobotControllerDelegate : public QObject
{
	Q_OBJECT
	Q_PROPERTY(qreal posX READ posX WRITE setPosX NOTIFY posXChanged)
	Q_PROPERTY(qreal posY READ posY WRITE setPosY NOTIFY posYChanged)
	Q_PROPERTY(qreal posZ READ posZ WRITE setPosZ NOTIFY posZChanged)
	Q_PROPERTY(qreal rotX READ rotX WRITE setRotX NOTIFY rotXChanged)
	Q_PROPERTY(qreal rotY READ rotY WRITE setRotY NOTIFY rotYChanged)
	Q_PROPERTY(qreal rotZ READ rotZ WRITE setRotZ NOTIFY rotZChanged)

	public:
		explicit RobotControllerDelegate(QObject *parent = nullptr);
		qreal posX() const;
		qreal posY() const;
		qreal posZ() const;
		qreal rotX() const;
		qreal rotY() const;
		qreal rotZ() const;

		Q_SLOT void setPosX(qreal x);
		Q_SLOT void setPosY(qreal y);
		Q_SLOT void setPosZ(qreal z);
		Q_SLOT void setRotX(qreal x);
		Q_SLOT void setRotY(qreal y);
		Q_SLOT void setRotZ(qreal z);
		Q_SLOT void reset();
	
		Q_SIGNAL void posXChanged();
		Q_SIGNAL void posYChanged();
		Q_SIGNAL void posZChanged();
		Q_SIGNAL void rotXChanged();
		Q_SIGNAL void rotYChanged();
		Q_SIGNAL void rotZChanged();

	private:
		qreal m_posX;
		qreal m_posY;
		qreal m_posZ;
		qreal m_rotX;
		qreal m_rotY;
		qreal m_rotZ;
};

} // namespace rf

#endif // ROBOT_CONTROLLER_DELEGATE_HPP
