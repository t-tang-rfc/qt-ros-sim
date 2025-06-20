/**
 * @file joystick_controller.hpp
 * 
 * @brief Joystick controller for robot simulation
 * 
 * @author: t-tang-rfc
 * 
 * @date:
 * - created on 2025-06-06
 * - updated on 2025-06-06
 **/

#ifndef JOYSTICK_CONTROLLER_HPP
#define JOYSTICK_CONTROLLER_HPP

#include <QObject>
#include <QtGlobal>
#include <QList>

#include <ros/ros.h>
#include <sensor_msgs/Joy.h>

namespace rf {

class JoystickController : public QObject
{
	Q_OBJECT

	public:
		explicit JoystickController(QObject* parent = nullptr);
		~JoystickController();

		Q_SIGNAL void moveX(qreal delta_x);

	private:	
		void joyCallback(const sensor_msgs::Joy::ConstPtr& msg);
		
		ros::NodeHandle nh_;
		ros::Subscriber joy_sub_;

		QList<qreal> robot_pose_; // a 6-element list for robot pose tracking
};

} // namespace rf

#endif // JOYSTICK_CONTROLLER_HPP
