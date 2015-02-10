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
#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include "luctor_base_class/luctor_base_class.hpp"

class Script : public LuctorBaseClass
{
  public:
	Script();
	Script( std::string name );
	Script( std::string id, std::string name );
	~Script();
	
	std::string getIdWithoutIdentifier();
	std::string get_filename() { return filename_; };

	void		set_filename ( std::string filename ) { filename_ = filename; };
	
	friend std::istream& operator >> (std::istream& stream, Script& script);
	friend std::ostream& operator << (std::ostream& stream, const Script& script);
	friend class ros::serialization::Serializer<Script>;

	static const std::string IDENTIFIER;
  
  protected:
  	std::string filename_;
};


namespace ros
{
	namespace message_traits
	{
		template<>
		struct MD5Sum<Script>
	    {
			static const char* value()
			{
				return "Okke1b53db61fb6aed406028aa6442a";
			}
			static const char* value(const Script& m) { return value(); }
			static const uint64_t static_value1 = 0x8b94c6b53db61fb4ULL;
			static const uint64_t static_value2 = 0xaed401028ad63324ULL;
	    };

		template<>
		struct DataType<Script>
		{
			static const char* value()
			{
				return "luctor_classes/script";
			}

			static const char* value(const Script& m) { return value(); }
	    };

		template<>
		struct Definition<Script>
		{
			static const char* value()
			{
				return "script data\n";
			}

			static const char* value(const Script& m){ return value(); }
	    };
	} // namespace message_traits

	namespace service_traits
	{
		template<>
		struct MD5Sum<Script>
	    {
			static const char* value()
			{
				return ros::message_traits::MD5Sum<Script>::value();
			}
			static const char* value(const Script& m) { return value(); }
			static const uint64_t static_value1 = ros::message_traits::MD5Sum<Script>::static_value1;
			static const uint64_t static_value2 = ros::message_traits::MD5Sum<Script>::static_value2;
	    };

		template<>
		struct DataType<Script>
		{
			static const char* value()
			{
				return ros::message_traits::DataType<Script>::value();
			}

			static const char* value(const Script& m) { return value(); }
	    };		
	}

	namespace serialization
	{
		template<>
		struct Serializer<Script>
		{
			template<typename Stream>
			inline static void write(Stream& stream, const Script& t)
			{
				ros::serialization::Serializer<LuctorBaseClass>::write(stream, (LuctorBaseClass)t);
				stream << t.filename_;
			}

			template<typename Stream>
			inline static void read(Stream& stream, Script& t)
			{
				ros::serialization::Serializer<LuctorBaseClass>::read(stream, (LuctorBaseClass&)t);
				stream >> t.filename_;
			}

			inline static uint32_t serializedLength(const Script& t)
			{
				uint32_t size = 0;
				size += ros::serialization::Serializer<LuctorBaseClass>::serializedLength((LuctorBaseClass)t);
				size += serializationLength(t.filename_);
				return size;
			}
		};
	} // namespace serialization
} // namespace ros

#endif // SCRIPT_HPP