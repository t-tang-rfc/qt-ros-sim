/**
 * @file joystick_controller.hpp
 * 
 * @brief implementation of the JoystickController class
 * 
 * @author: t-tang-rfc
 * 
 * @date:
 * - created on 2025-06-06
 * - updated on 2025-06-06
 **/

#include "joystick_controller.hpp"

JoystickController::JoystickController(QObject* parent)
	: QObject(parent)
	, nh_(ros::NodeHandle())
	, joy_sub_(nh_.subscribe("joy", 10, &JoystickController::joyCallback, this))
	, robot_pose_({0, 0, 0, 0, 0, 0})
{
	// Add custom initialization if needed
	ROS_INFO("JoystickController initialized!");
}

JoystickController::~JoystickController() = default;

void JoystickController::joyCallback(const sensor_msgs::Joy::ConstPtr& msg)
{
	ROS_INFO("Joy callback called!");
}
