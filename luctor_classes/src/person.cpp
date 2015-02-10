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
#include "person.hpp"

const std::string Person::IDENTIFIER = std::string("person");

Person::Person()
	: LuctorBaseClass()
{

}

Person::Person( std::string name )
	: LuctorBaseClass( name )
{
	
}

Person::Person( std::string id, std::string name )
	: LuctorBaseClass( id, name )
{

}

Person::~Person()
{

}

std::string Person::getIdWithoutIdentifier()
{
	std::string id_without_identifier = id_;
	return id_without_identifier.erase(0,IDENTIFIER.size());
}

std::istream& operator >> (std::istream& stream, Person& p)
{
	stream 	>> (LuctorBaseClass&) p;

	//stream >> member;
	
	return stream;
}

std::ostream& operator << (std::ostream& stream, const Person& p)
{
	stream 	<< (LuctorBaseClass) p;

	//stream << member << " ";
	
	return stream;
}
