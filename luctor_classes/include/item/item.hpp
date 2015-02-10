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
#ifndef ITEM_HPP
#define ITEM_HPP

#include "bounding_box/bounding_box.hpp"
#include "luctor_base_class/luctor_base_class.hpp"

class Item : public LuctorBaseClass
{
  public:
    Item();
    Item( std::string name );
    Item( std::string id, std::string name );
  	~Item();

    BoundingBox get_bounding_box() const { return bounding_box_; };

    void        set_bounding_box( BoundingBox bounding_box ){ bounding_box_ = bounding_box; };
    std::string getIdWithoutIdentifier() const;
    
    friend std::istream& operator >> (std::istream& stream, Item& item);
    friend std::ostream& operator << (std::ostream& stream, const Item& item);
    friend class ros::serialization::Serializer<Item>;

    static const std::string IDENTIFIER;
    
  private:   
    BoundingBox bounding_box_;  
};

namespace ros
{
    namespace message_traits
    {
        template<>
        struct MD5Sum<Item>
        {
            static const char* value()
            {
            return "8b94c1b53db61fb6aed406028ad6552a";
            }
            static const char* value(const Item& m) { return value(); }
            static const uint64_t static_value1 = 0x8b94c1b53db61fb5ULL;
            static const uint64_t static_value2 = 0xaed406028ad63325ULL;
        };

        template<>
        struct DataType<Item>
        {
            static const char* value()
            {
                return "luctor_classes/item";
            }
            static const char* value(const Item& m) { return value(); }
        };

        template<>
        struct Definition<Item>
        {
            static const char* value()
            {
               return "item data\n";
            }
            static const char* value(const Item& m){ return value(); }
        };

    } // namespace message_traits

    namespace service_traits
    {
        template<>
        struct MD5Sum<Item>
        {
            static const char* value()
            {
                return ros::message_traits::MD5Sum<Item>::value();
            }
            static const char* value(const Item& m) { return value(); }
            static const uint64_t static_value1 = ros::message_traits::MD5Sum<Item>::static_value1;
            static const uint64_t static_value2 = ros::message_traits::MD5Sum<Item>::static_value2;
        };

        template<>
        struct DataType<Item>
        {
            static const char* value()
            {
                return ros::message_traits::DataType<Item>::value();
            }
            static const char* value(const Item& m) { return value(); }
        };    
    }

    namespace serialization
    {
        template<>
        struct Serializer<Item>
        {
            template<typename Stream>
            inline static void write(Stream& stream, const Item& t)
            {
                ros::serialization::Serializer<LuctorBaseClass>::write(stream, (LuctorBaseClass)t);
                stream << t.bounding_box_;
            }

            template<typename Stream>
            inline static void read(Stream& stream, Item& t)
            {
                ros::serialization::Serializer<LuctorBaseClass>::read(stream, (LuctorBaseClass&)t);
                stream >> t.bounding_box_;
            }

            inline static uint32_t serializedLength(const Item& t)
            {
                uint32_t size = 0;
                size += ros::serialization::Serializer<LuctorBaseClass>::serializedLength((LuctorBaseClass)t);
                size += serializationLength(t.bounding_box_);
                return size;
            }
        };    
    } // namespace serialization
} // namespace ros

#endif // ITEM_HPP