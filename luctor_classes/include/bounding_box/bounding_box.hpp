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
#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include <ros/message_operations.h>
#include <ros/message_traits.h>
#include <ros/serialization.h>
#include <ros/service_traits.h>

#include <geometry_msgs/Point.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>

#include "rose_common/common.hpp"
#include "rose_conversions/conversions.hpp"

class BoundingBox
{
  public:
	BoundingBox();
	BoundingBox( geometry_msgs::PoseStamped pose, double width, double heigth, double depth);
	~BoundingBox();

	bool 		isSet() { return is_set_; };
	void 		unset() { is_set_ = false; };
	std::string toString();
	
	geometry_msgs::Point 		getCenter() const;
	geometry_msgs::Quaternion 	getOrientation() const;
	geometry_msgs::PoseStamped	getPoseStamped() const;
	geometry_msgs::Pose 		getPose() const;
	std::string					getFrame() const;
	double 						getHeigth() const;
	double 						getWidth() const;
	double 						getDepth() const;

	friend std::istream& operator >> (std::istream& stream, BoundingBox& bb);
	friend std::ostream& operator << (std::ostream& stream, const BoundingBox& bb);
	friend class ros::serialization::Serializer<BoundingBox>;

  private:
  	void updatePoseStamped();

	bool is_set_;

	geometry_msgs::PoseStamped	pose_stamped_;
	std::string 				frame_id_;
	int 						seq_;
	geometry_msgs::Point 		position_;
	geometry_msgs::Quaternion 	orientation_;

	double 						heigth_;
	double 						width_;
	double 						depth_;
};


namespace ros
{
	namespace message_traits
	{
		template<>
		struct MD5Sum<BoundingBox>
		{
			static const char* value()
			{
				return "8b94c1b53db61fb6aed406028ad6442a";
			}
			static const char* value(const BoundingBox& m) { return value(); }
			static const uint64_t static_value1 = 0x8b94c1b53db61fb4ULL;
			static const uint64_t static_value2 = 0xaed406028ad63324ULL;
	    };

		template<>
		struct DataType<BoundingBox>
		{
			static const char* value()
			{
				return "luctor_classes/bounding_box";
			}

			static const char* value(const BoundingBox& m) { return value(); }
	    };

		template<>
		struct Definition<BoundingBox>
		{
			static const char* value()
			{
				return "bounding box data\n";
			}

			static const char* value(const BoundingBox& m){ return value(); }
	    };

	} // namespace message_traits

	namespace service_traits
	{
		template<>
		struct MD5Sum<BoundingBox>
	    {
			static const char* value()
			{
				return ros::message_traits::MD5Sum<BoundingBox>::value();
			}
			static const char* value(const BoundingBox& m) { return value(); }
			static const uint64_t static_value1 = ros::message_traits::MD5Sum<BoundingBox>::static_value1;
			static const uint64_t static_value2 = ros::message_traits::MD5Sum<BoundingBox>::static_value2;
	    };

		template<>
		struct DataType<BoundingBox>
		{
			static const char* value()
			{
				return ros::message_traits::DataType<BoundingBox>::value();
			}

	      static const char* value(const BoundingBox& m) { return value(); }
	    };		
	}

	namespace serialization
	{
		template<>
		struct Serializer<BoundingBox>
		{
			template<typename Stream, typename T>
			inline static void allInOne(Stream& stream, T t)
			{
				stream.next(t.is_set_);
				stream.next(t.pose_stamped_);
				stream.next(t.frame_id_);
				stream.next(t.seq_);
				stream.next(t.position_);
				stream.next(t.orientation_);
				stream.next(t.width_);
				stream.next(t.heigth_);
				stream.next(t.depth_);
			}

			ROS_DECLARE_ALLINONE_SERIALIZER;
		};

	} // namespace serialization

	namespace message_operations
	{
		template<>
		struct Printer<BoundingBox>
		{
			template<typename Stream> static void stream(Stream& s, const std::string& indent, const BoundingBox &bb) 
			{
				//todo
			}
		};
	}
} // namespace ros

#endif // BOUNDING_BOX_HPP