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
#include "waypoint/waypoint.hpp"

const std::string Waypoint::IDENTIFIER = std::string("waypoint");

Waypoint::Waypoint()
	: LuctorBaseClass()
	, is_set_ ( false )
{
	initializeValues();
}

Waypoint::Waypoint( std::string name )
	: LuctorBaseClass( name )
	, is_set_ ( false )
{
	initializeValues();
}

Waypoint::Waypoint( std::string id, std::string name )
	: LuctorBaseClass( id, name )
	, is_set_ ( false )
{
	initializeValues();
}

Waypoint::~Waypoint()
{

}

std::string Waypoint::getFrame() const 
{
	return frame_id_;
}

void Waypoint::initializeValues()
{
	pose_stamped_ 	= PoseStamped(); 
	frame_id_  	 	= "base_link";
	seq_ 	  	 	= 0;
	position_ 		= geometry_msgs::Point();
	orientation_ 	= geometry_msgs::Quaternion();
}

void Waypoint::updatePoseStamped()
{
	pose_stamped_.header.frame_id 	= frame_id_;
	pose_stamped_.header.seq 	  	= seq_;
	pose_stamped_.header.stamp 	    = ros::Time::now();
	pose_stamped_.pose.position 	= position_;
	pose_stamped_.pose.orientation	= orientation_;
}

void Waypoint::set( PoseStamped pose_stamped )
{
	is_set_ 		= true;
	pose_stamped_ 	= pose_stamped; 
	frame_id_  	 	= pose_stamped.header.frame_id;
	seq_ 	  	 	= pose_stamped.header.seq;
	position_ 		= pose_stamped.pose.position;
	orientation_ 	= pose_stamped.pose.orientation;
}

std::string Waypoint::getIdWithoutIdentifier() const
{
	std::string id_without_identifier = id_;
	return id_without_identifier.erase(0,IDENTIFIER.size());
}

std::istream& operator >> (std::istream& stream, Waypoint& waypoint)
{
	stream 	>> (LuctorBaseClass&) waypoint
			>> waypoint.is_set_ 
			>> waypoint.frame_id_     
			>> waypoint.seq_ 		
			>> waypoint.position_.x 
			>> waypoint.position_.y 
			>> waypoint.position_.z 
			>> waypoint.orientation_.x 
			>> waypoint.orientation_.y 
			>> waypoint.orientation_.z 
			>> waypoint.orientation_.w;

	waypoint.updatePoseStamped();

	return stream;
}

std::ostream& operator << (std::ostream& stream, const Waypoint& waypoint)
{
	stream 	<< (LuctorBaseClass) waypoint
			<< waypoint.is_set_     	<< " "
			<< waypoint.frame_id_     	<< " "
			<< waypoint.seq_ 			<< " "
			<< waypoint.position_.x 	<< " "
			<< waypoint.position_.y 	<< " "
			<< waypoint.position_.z 	<< " "
			<< waypoint.orientation_.x 	<< " "
			<< waypoint.orientation_.y 	<< " "
			<< waypoint.orientation_.z 	<< " "
			<< waypoint.orientation_.w 	<< " ";
		   
	return stream;
}


