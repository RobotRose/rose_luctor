/***********************************************************************************
* Copyright: Rose B.V. (2014)
*
* Revision History:
*	Author: Mathijs de Langen
*	Date  : 2014/04/11
* 		- File created.
*
* Description:
*	description
* 
***********************************************************************************/
#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "luctor_base_class/luctor_base_class.hpp"

class Resource : public LuctorBaseClass
{
  public:
	Resource();
	Resource( std::string name );
	Resource( std::string id, std::string name );
	~Resource();
	
	std::string getIdWithoutIdentifier();
	std::string get_filename() { return filename_; };

	void		set_filename ( std::string filename ) { filename_ = filename; };
	
	friend std::istream& operator >> (std::istream& stream, Resource& Resource);
	friend std::ostream& operator << (std::ostream& stream, const Resource& Resource);
	friend class ros::serialization::Serializer<Resource>;

	static const std::string IDENTIFIER;
  
  protected:
  	std::string filename_;
};


namespace ros
{
	namespace message_traits
	{
		template<>
		struct MD5Sum<Resource>
	    {
			static const char* value()
			{
				return "8b94c1b53db62fb6aed406028aa6442a";
			}
			static const char* value(const Resource& m) { return value(); }
			static const uint64_t static_value1 = 0x8b94c6b73db61fb4ULL;
			static const uint64_t static_value2 = 0xaed201028ad63324ULL;
	    };

		template<>
		struct DataType<Resource>
		{
			static const char* value()
			{
				return "luctor_classes/resource";
			}

			static const char* value(const Resource& m) { return value(); }
	    };

		template<>
		struct Definition<Resource>
		{
			static const char* value()
			{
				return "resource data\n";
			}

			static const char* value(const Resource& m){ return value(); }
	    };
	} // namespace message_traits

	namespace service_traits
	{
		template<>
		struct MD5Sum<Resource>
	    {
			static const char* value()
			{
				return ros::message_traits::MD5Sum<Resource>::value();
			}
			static const char* value(const Resource& m) { return value(); }
			static const uint64_t static_value1 = ros::message_traits::MD5Sum<Resource>::static_value1;
			static const uint64_t static_value2 = ros::message_traits::MD5Sum<Resource>::static_value2;
	    };

		template<>
		struct DataType<Resource>
		{
			static const char* value()
			{
				return ros::message_traits::DataType<Resource>::value();
			}

			static const char* value(const Resource& m) { return value(); }
	    };		
	}

	namespace serialization
	{
		template<>
		struct Serializer<Resource>
		{
			template<typename Stream>
			inline static void write(Stream& stream, const Resource& t)
			{
				ros::serialization::Serializer<LuctorBaseClass>::write(stream, (LuctorBaseClass)t);
				stream << t.filename_;
			}

			template<typename Stream>
			inline static void read(Stream& stream, Resource& t)
			{
				ros::serialization::Serializer<LuctorBaseClass>::read(stream, (LuctorBaseClass&)t);
				stream >> t.filename_;
			}

			inline static uint32_t serializedLength(const Resource& t)
			{
				uint32_t size = 0;
				size += ros::serialization::Serializer<LuctorBaseClass>::serializedLength((LuctorBaseClass)t);
				size += serializationLength(t.filename_);
				return size;
			}
		};
	} // namespace serialization
} // namespace ros

#endif // RESOURCE_HPP