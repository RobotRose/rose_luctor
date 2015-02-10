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
#include "luctor_base_class.hpp"

const std::string LuctorBaseClass::IDENTIFIER = std::string("luctor_base_class");

LuctorBaseClass::LuctorBaseClass()
	: id_set_ ( false )
	, id_ ( "none" )
	, temp_ ( false )
{
	set_name( "none" );
}

LuctorBaseClass::LuctorBaseClass( std::string name )
	: id_set_ ( false )
	, id_ ( "none" )
	, temp_ ( false )
{
	set_name( name );
}

LuctorBaseClass::LuctorBaseClass( std::string id, std::string name )
	: id_set_ ( true )
	, id_ ( id )
	, temp_ ( false )
{
	set_name( name );
}

LuctorBaseClass::~LuctorBaseClass()
{

}

void LuctorBaseClass::set_name ( std::string name )
{
	std::replace( name.begin(), name.end(), ' ', '_');
	name_ = name;
}

std::string const LuctorBaseClass::get_name()
{
	std::string name ( name_ );
	std::replace( name.begin(), name.end(), '_', ' ');
	return name;
}

std::string const LuctorBaseClass::get_id()
{
	return id_;
}

std::string const LuctorBaseClass::getIdWithoutIdentifier()
{
	std::string id_without_identifier = id_;
	return id_without_identifier.erase(0,IDENTIFIER.size());
}

std::istream& operator >> (std::istream& stream, LuctorBaseClass& item)
{
	stream 	>> item.id_set_
			>> item.id_ 
			>> item.name_ 
			>> item.temp_;
	return stream;
}

std::ostream& operator << (std::ostream& stream, const LuctorBaseClass& item)
{
	stream 	<< item.id_set_ << " "
			<< item.id_ << " " 
			<< item.name_ << " "
			<< item.temp_ << " ";
	return stream;
}