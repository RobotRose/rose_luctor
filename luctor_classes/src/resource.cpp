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
#include "resource.hpp"

const std::string Resource::IDENTIFIER = std::string("resource");

Resource::Resource()
	: LuctorBaseClass()
{
	
}

Resource::Resource( std::string name )
	: LuctorBaseClass( name )
{
	
}

Resource::Resource( std::string id, std::string name )
	: LuctorBaseClass( id, name )
{
	
}

Resource::~Resource()
{

}

std::string Resource::getIdWithoutIdentifier()
{
	std::string id_without_identifier = id_;
	return id_without_identifier.erase(0,IDENTIFIER.size());
}

std::istream& operator >> (std::istream& stream, Resource& resource)
{
	stream 	>> (LuctorBaseClass&) resource
			>> resource.filename_;
	
	return stream;
}

std::ostream& operator << (std::ostream& stream, const Resource& resource)
{
	stream 	<< (LuctorBaseClass) resource
			<< resource.filename_ << " ";
	
	return stream;
}
