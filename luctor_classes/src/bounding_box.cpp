/***********************************************************************************
* Copyright: Rose B.V. (2014)
*
* Revision History:
*	Author: Mathijs de Langen
*	Date  : 2014/01/24
* 		- File created.
*
* Description:
*	description
* 
***********************************************************************************/
#include "bounding_box/bounding_box.hpp"

BoundingBox::BoundingBox()
	: is_set_ ( false )
	, heigth_ ( 0 )
	, width_ ( 0 )
	, depth_ ( 0 )
{
	pose_stamped_   = geometry_msgs::PoseStamped();
	frame_id_ 		= "base_link";
	seq_			= 0;
	position_		= geometry_msgs::Point();
	orientation_	= geometry_msgs::Quaternion();
}

BoundingBox::BoundingBox( geometry_msgs::PoseStamped pose_stamped, double width, double heigth, double depth )
	: is_set_ ( true )
	, pose_stamped_ ( pose_stamped )
	, width_ ( width )
	, heigth_ ( heigth )
	, depth_ ( depth )
{
	frame_id_ 		= pose_stamped_.header.frame_id;
	seq_			= pose_stamped_.header.seq;
	position_		= pose_stamped_.pose.position;
	orientation_	= pose_stamped_.pose.orientation;
}

BoundingBox::~BoundingBox()
{

}

void BoundingBox::updatePoseStamped()
{
	pose_stamped_.header.frame_id 	= frame_id_;
	pose_stamped_.header.seq 	  	= seq_;
	pose_stamped_.header.stamp 	    = ros::Time::now();
	pose_stamped_.pose.position 	= position_;
	pose_stamped_.pose.orientation	= orientation_;
}

std::string BoundingBox::toString()
{
	return "(" + rose_conversions::doubleToString(getCenter().x) 
		 + "," + rose_conversions::doubleToString(getCenter().y) 
		 + "," + rose_conversions::doubleToString(getCenter().z) + ")";
}

geometry_msgs::Point BoundingBox::getCenter() const 
{
	return position_;
}

geometry_msgs::Quaternion BoundingBox::getOrientation() const 
{
	return orientation_;
}

geometry_msgs::PoseStamped BoundingBox::getPoseStamped() const 
{
	geometry_msgs::PoseStamped pose_now = pose_stamped_;
	pose_now.header.stamp = ros::Time::now();
	return pose_now;
}

geometry_msgs::Pose BoundingBox::getPose() const 
{
	return pose_stamped_.pose;
}

std::string BoundingBox::getFrame() const 
{
	return frame_id_;
}

double BoundingBox::getWidth() const 
{
	return width_;
}

double BoundingBox::getHeigth() const 
{
	return heigth_;
}

double BoundingBox::getDepth() const 
{
	return depth_;
}

std::istream& operator >> (std::istream& stream, BoundingBox& bb)
{
	stream 	>> bb.is_set_ 		
			>> bb.frame_id_		
			>> bb.seq_ 			
			>> bb.position_.x 	
			>> bb.position_.y 	
			>> bb.position_.z 	
			>> bb.orientation_.x 
			>> bb.orientation_.y 
			>> bb.orientation_.z 
			>> bb.orientation_.w 
	       	>> bb.width_ 		
	       	>> bb.heigth_ 		
	       	>> bb.depth_;

	bb.updatePoseStamped();

	return stream;
}

std::ostream& operator << (std::ostream& stream, const BoundingBox& bb)
{
	stream 	<< bb.is_set_ 		<< " "
			<< bb.frame_id_     << " "
			<< bb.seq_ 			<< " "
			<< bb.position_.x 	<< " "
			<< bb.position_.y 	<< " "
			<< bb.position_.z 	<< " "
			<< bb.orientation_.x << " "
			<< bb.orientation_.y << " "
			<< bb.orientation_.z << " "
			<< bb.orientation_.w << " "
	       	<< bb.width_ 		<< " "
	       	<< bb.heigth_ 		<< " "
	       	<< bb.depth_ 		<< " ";
	       	
	return stream;
}


