#include "kinematics_toolbox/kinematics_ros_types.h"

using namespace kinematics_ros_types;

////////////////////////////////////////////////////////////////////////////////
// Vector3 operators
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Twist operators
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Pose2D operators
////////////////////////////////////////////////////////////////////////////////
  
geometry_msgs::Twist kinematics_ros_types::calculateError(
    const geometry_msgs::Pose2D& desired, const geometry_msgs::Pose2D& current )
{
  // this is homogeneous(current).inverse * homogeneous(desired)
  geometry_msgs::Twist diff;

  diff.linear.x = ( desired.x - current.x ) * cos( current.theta )
    + ( desired.y - current.y ) * sin( current.theta );

  diff.linear.y = ( desired.y - current.y ) * cos( current.theta )
    - ( desired.y - current.y ) * sin( current.theta );

  diff.linear.z = 0;
  diff.angular.x = 0;
  diff.angular.y = 0;
  diff.angular.z = current.theta - desired.theta;
  return diff;
}
