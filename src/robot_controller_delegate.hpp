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
#include <QList>
#include <QtQml/qqml.h>

namespace rf {

class RobotControllerDelegate : public QObject
{
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(QList<qreal> pose READ getPose WRITE setPose NOTIFY poseChanged)

	public:
		explicit RobotControllerDelegate(QObject *parent = nullptr);
		~RobotControllerDelegate();

		QList<qreal> getPose() const;

		Q_SLOT void setPose(const QList<qreal>& pose);
		Q_SLOT void reset();

		Q_SIGNAL void poseChanged();

	private:
		QList<qreal> pose_;
};

} // namespace rf

#endif // ROBOT_CONTROLLER_DELEGATE_HPP
