#include "attraction.h"

Attraction::Attraction()
{
	this->_id = "";
	this->_code = "";
	this->_name = "";
}


string Attraction::id()
{
	return this->_id;
}

string Attraction::id(string id)
{
	this->_id = id;
	return this->id();
}

string Attraction::code()
{
	return this->_code;
}

string Attraction::code(string code)
{
	this->_code = code;
	return this->code();
}

string Attraction::name()
{
	return this->_name;
}

string Attraction::name(string name)
{
	this->_name = name;
	return this->name();
}
