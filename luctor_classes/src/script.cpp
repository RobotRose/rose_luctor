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
#include "script/script.hpp"

const std::string Script::IDENTIFIER = std::string("script");

Script::Script()
	: LuctorBaseClass()
{
	
}

Script::Script( std::string name )
	: LuctorBaseClass( name )
{
	
}

Script::Script( std::string id, std::string name )
	: LuctorBaseClass( id, name )
{
	
}

Script::~Script()
{

}

std::string Script::getIdWithoutIdentifier()
{
	std::string id_without_identifier = id_;
	return id_without_identifier.erase(0,IDENTIFIER.size());
}

std::istream& operator >> (std::istream& stream, Script& script)
{
	stream 	>> (LuctorBaseClass&) script
			>> script.filename_;
	
	return stream;
}

std::ostream& operator << (std::ostream& stream, const Script& script)
{
	stream 	<< (LuctorBaseClass) script
			<< script.filename_ << " ";
	
	return stream;
}
