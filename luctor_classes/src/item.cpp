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
#include "item.hpp"

const std::string Item::IDENTIFIER = std::string("item");

Item::Item()
	: LuctorBaseClass()
{

}

Item::Item( std::string name )
	: LuctorBaseClass ( name )
{

}

Item::Item( std::string id, std::string name )
	: LuctorBaseClass( id, name )
{

}

Item::~Item()
{

}

std::string Item::getIdWithoutIdentifier() const
{
	std::string id_without_identifier = id_;
	return id_without_identifier.erase(0,IDENTIFIER.size());
}

std::istream& operator >> (std::istream& stream, Item& item)
{
	stream  >> (LuctorBaseClass&) item
			>> item.bounding_box_;

	return stream;
}

std::ostream& operator << (std::ostream& stream, const Item& item)
{
	stream 	<< (LuctorBaseClass) item
			<< item.bounding_box_ << " ";

	return stream;
}
