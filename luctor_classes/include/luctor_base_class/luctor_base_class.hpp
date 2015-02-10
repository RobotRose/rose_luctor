/***********************************************************************************
* Copyright: Rose B.V. (2014)
*
* Revision History:
* Author: Mathijs de Langen
* Date  : 2014/01/24
*     - File created.
*
* Description:
* description
* 
***********************************************************************************/
#ifndef LUCTOR_BASE_CLASS_HPP
#define LUCTOR_BASE_CLASS_HPP

#include <ros/ros.h>
#include <ros/message_operations.h>
#include <ros/message_traits.h>
#include <ros/serialization.h>
#include <ros/service_traits.h>
#include <stdio.h>

#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>

#include <vector_serialization.hpp>

class LuctorBaseClass
{
  public:
	LuctorBaseClass();
	LuctorBaseClass( std::string name );
	LuctorBaseClass( std::string id, std::string name );
	virtual ~LuctorBaseClass();

	std::string const get_name();
	std::string const get_id();
	std::string const getIdWithoutIdentifier();
	bool 		const is_temp() const { return temp_; };
	bool        const hasId(){ return id_set_; };

	void		set_id( std::string id ){ id_ = id; id_set_ = true; };
	void 		set_temp( bool temp ){ temp_ = temp; };

	friend std::istream& operator >> (std::istream& stream, LuctorBaseClass& base);
	friend std::ostream& operator << (std::ostream& stream, const LuctorBaseClass& base);
	friend class ros::serialization::Serializer<LuctorBaseClass>;
  
  	static const std::string IDENTIFIER;
  	
  	void 		set_name( std::string name );
  protected:

	bool        id_set_;
	bool 		temp_;
	std::string id_;
	std::string name_;
};


namespace ros
{
	namespace message_traits
	{
		template<>
		struct MD5Sum<LuctorBaseClass>
		{
			static const char* value()
			{
				return "8b94c1b53db61xb6aed406028ad6552a";
			}
			static const char* value(const LuctorBaseClass& m) { return value(); }
			static const uint64_t static_value1 = 0x8b94c1b53db61fb5ULL;
			static const uint64_t static_value2 = 0xaed406028ad63325ULL;
		};

		template<>
		struct DataType<LuctorBaseClass>
		{
			static const char* value()
			{
				return "LuctorBaseClass";
			}

			static const char* value(const LuctorBaseClass& m) { return value(); }
		};

		template<>
		struct Definition<LuctorBaseClass>
		{
			static const char* value()
			{
				return "LuctorBaseClass data\n";
			}

			static const char* value(const LuctorBaseClass& m){ return value(); }
		};

	} // namespace message_traits
	
	namespace service_traits
	{
		template<>
		struct MD5Sum<LuctorBaseClass>
			{
				static const char* value()
				{
					return ros::message_traits::MD5Sum<LuctorBaseClass>::value();
				}
				static const char* value(const LuctorBaseClass& m) { return value(); }
				static const uint64_t static_value1 = ros::message_traits::MD5Sum<LuctorBaseClass>::static_value1;
				static const uint64_t static_value2 = ros::message_traits::MD5Sum<LuctorBaseClass>::static_value2;
			};

		template<>
		struct DataType<LuctorBaseClass>
		{
				static const char* value()
				{
					return ros::message_traits::DataType<LuctorBaseClass>::value();
				}

				static const char* value(const LuctorBaseClass& m) { return value(); }
			};    
	}
	namespace serialization
	{
		template<>
		struct Serializer<LuctorBaseClass>
		{
			template<typename Stream, typename T>
			inline static void allInOne(Stream& stream, T t)
			{
				stream.next(t.id_set_);
				stream.next(t.id_);
				stream.next(t.name_);
				stream.next(t.temp_);
			}

			ROS_DECLARE_ALLINONE_SERIALIZER;
		};


	} // namespace serialization
} // namespace ros


#endif // LUCTOR_BASE_CLASS_HPP