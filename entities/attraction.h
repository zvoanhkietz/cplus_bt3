#ifndef _ATTRACTION_H_
#define _ATTRACTION_H_

#include <iostream>

using namespace std;

class Attraction
{
	protected:
		string _id;
		string _code;
		string _name;
	public:
		Attraction();
		string id();
		string id(string id);
		string code();
		string code(string code);
		string name();
		string name(string name);
};

#endif