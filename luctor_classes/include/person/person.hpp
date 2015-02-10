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
#ifndef PERSON_HPP
#define PERSON_HPP

#include "luctor_base_class.hpp"

class Person : public LuctorBaseClass
{
  public:
  	Person();
  	Person( std::string name );
	Person( std::string id, std::string name );
	~Person();
	
    std::string getIdWithoutIdentifier();

	friend std::istream& operator >> (std::istream& stream, Person& bb);
	friend std::ostream& operator << (std::ostream& stream, const Person& bb);
	friend class ros::serialization::Serializer<Person>;

	static const std::string IDENTIFIER;
};

namespace ros
{
	namespace message_traits
	{
		template<>
		struct MD5Sum<Person>
	    {
			static const char* value()
			{
				return "8b94c1b53db61gb6aed406028aa6442a";
			}
			static const char* value(const Person& m) { return value(); }
			static const uint64_t static_value1 = 0x9b94c6b53db61fb4ULL;
			static const uint64_t static_value2 = 0xaed402028ad63324ULL;
	    };

		template<>
		struct DataType<Person>
		{
			static const char* value()
			{
				return "luctor_classes/Person";
			}

			static const char* value(const Person& m) { return value(); }
	    };

		template<>
		struct Definition<Person>
		{
			static const char* value()
			{
				return "Person data\n";
			}

			static const char* value(const Person& m){ return value(); }
	    };
	} // namespace message_traits

	namespace service_traits
	{
		template<>
		struct MD5Sum<Person>
	    {
			static const char* value()
			{
				return ros::message_traits::MD5Sum<Person>::value();
			}
			static const char* value(const Person& m) { return value(); }
			static const uint64_t static_value1 = ros::message_traits::MD5Sum<Person>::static_value1;
			static const uint64_t static_value2 = ros::message_traits::MD5Sum<Person>::static_value2;
	    };

		template<>
		struct DataType<Person>
		{
			static const char* value()
			{
				return ros::message_traits::DataType<Person>::value();
			}

			static const char* value(const Person& m) { return value(); }
	    };		
	}

	namespace serialization
	{
		template<>
		struct Serializer<Person>
		{
			template<typename Stream>
			inline static void write(Stream& stream, const Person& t)
			{
				ros::serialization::Serializer<LuctorBaseClass>::write(stream, (LuctorBaseClass)t);
			}

			template<typename Stream>
			inline static void read(Stream& stream, Person& t)
			{
				ros::serialization::Serializer<LuctorBaseClass>::read(stream, (LuctorBaseClass&)t);
			}

			inline static uint32_t serializedLength(const Person& t)
			{
				uint32_t size = 0;
				size += ros::serialization::Serializer<LuctorBaseClass>::serializedLength((LuctorBaseClass)t);
				return size;
			}
		};
	} // namespace serialization
} // namespace ros

#endif // PERSON_HPP