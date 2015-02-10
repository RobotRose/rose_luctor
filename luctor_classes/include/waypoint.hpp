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
#ifndef WAYPOINT_HPP
#define WAYPOINT_HPP

#include <iostream>
#include <stdio.h>

#include "rose_common/common.hpp"
#include "luctor_base_class.hpp"

using geometry_msgs::Point;
using geometry_msgs::Pose;
using geometry_msgs::PoseStamped;
using geometry_msgs::Quaternion;

class Waypoint : public LuctorBaseClass
{
  public:
	Waypoint();
	Waypoint( std::string name );
	Waypoint( std::string id, std::string name );
	~Waypoint();

	std::string toString();
	bool 		isSet() const { return is_set_; };
	void 		unset(){ is_set_ = false; };
	
	std::string getFrame() const;
	PoseStamped	getPoseStamped() const { return pose_stamped_; }; 
	Point		getPosition() const { return pose_stamped_.pose.position; }; 
	Quaternion	getOrientation() const { return pose_stamped_.pose.orientation; }; 

	void 		set( PoseStamped pose_stamped );
	std::string getIdWithoutIdentifier() const;

	friend std::istream& operator >> (std::istream& stream, Waypoint& waypoint);
	friend std::ostream& operator << (std::ostream& stream, const Waypoint& waypoint);
	friend class ros::serialization::Serializer<Waypoint>;

	static const std::string IDENTIFIER;

  private:
  	void initializeValues();
  	void updatePoseStamped();

  	bool 		is_set_;

  	PoseStamped pose_stamped_;
	std::string	frame_id_;
	int 		seq_;
	Point 		position_;
	Quaternion  orientation_;
	
};

namespace ros
{
	namespace message_traits
	{
		template<>
		struct MD5Sum<Waypoint>
	    {
			static const char* value()
			{
				return "8b94c1b53db71fb6aed416028ad6442a";
			}
			static const char* value(const Waypoint& m) { return value(); }
			static const uint64_t static_value1 = 0x8c94c1b51db61fb4ULL;
			static const uint64_t static_value2 = 0xafd406018ad63324ULL;
	    };

		template<>
		struct DataType<Waypoint>
		{
			static const char* value()
			{
				return "luctor_classes/waypoint";
			}

			static const char* value(const Waypoint& m) { return value(); }
	    };

		template<>
		struct Definition<Waypoint>
		{
			static const char* value()
			{
				return "waypoint data\n";
			}

			static const char* value(const Waypoint& m){ return value(); }
	    };

	} // namespace message_traits

	namespace service_traits
	{
		template<>
		struct MD5Sum<Waypoint>
	    {
			static const char* value()
			{
				return ros::message_traits::MD5Sum<Waypoint>::value();
			}
			static const char* value(const Waypoint& m) { return value(); }
			static const uint64_t static_value1 = ros::message_traits::MD5Sum<Waypoint>::static_value1;
			static const uint64_t static_value2 = ros::message_traits::MD5Sum<Waypoint>::static_value2;
	    };

		template<>
		struct DataType<Waypoint>
		{
			static const char* value()
			{
				return ros::message_traits::DataType<Waypoint>::value();
			}

			static const char* value(const Waypoint& m) { return value(); }
	    };		
	}

	namespace serialization
	{
		template<>
		struct Serializer<Waypoint>
		{
			template<typename Stream>
			inline static void write(Stream& stream, const Waypoint& t)
			{
				ros::serialization::Serializer<LuctorBaseClass>::write(stream, (LuctorBaseClass)t);
				stream << t.is_set_;
				stream << t.pose_stamped_;
				stream << t.frame_id_;
				stream << t.seq_;
				stream << t.position_;
				stream << t.orientation_;
			}

			template<typename Stream>
			inline static void read(Stream& stream, Waypoint& t)
			{
				ros::serialization::Serializer<LuctorBaseClass>::read(stream, (LuctorBaseClass&)t);
				stream >> t.is_set_;
				stream >> t.pose_stamped_;
				stream >> t.frame_id_;
				stream >> t.seq_;
				stream >> t.position_;
				stream >> t.orientation_;
			}

			inline static uint32_t serializedLength(const Waypoint& t)
			{
				uint32_t size = 0;
				size += ros::serialization::Serializer<LuctorBaseClass>::serializedLength((LuctorBaseClass)t);
				size += serializationLength(t.is_set_);
				size += serializationLength(t.pose_stamped_);
				size += serializationLength(t.frame_id_);
				size += serializationLength(t.seq_);
				size += serializationLength(t.position_);
				size += serializationLength(t.orientation_);
				return size;
			}
		};

	} // namespace serialization

	namespace message_operations
	{
		template<>
		struct Printer<Waypoint>
		{
			template<typename Stream> static void stream(Stream& s, const std::string& indent, const Waypoint &bb) 
			{
				//todo
			}
		};
	}
} // namespace ros
#endif // WAYPOINT_HPP