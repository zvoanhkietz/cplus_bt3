#include "ticket.h"


Ticket::Ticket()
{
	this->_ticketCode      = "";
	
	this->_ticketTitle1    = "";
	this->_ticketTitle2    = "";
	this->_ticketTitle3    = "";
	this->_ticketTitle4    = "";
	this->_ticketTitle5    = "";

	this->_ticketRelation1 = "";
	this->_ticketRelation2 = "";
	this->_ticketRelation3 = "";
	this->_ticketRelation4 = "";
	this->_ticketRelation5 = "";
}

vector<string> Ticket::_split(string input, char separator)
{
	vector<string> results;
	stringstream ss(input);
	string token;
	while(ss.good()) {
		getline(ss, token, separator);
		results.push_back(token);
	}
	return results;
}

string Ticket::ticketCode()
{
	return this->_ticketCode;
}

string Ticket::ticketCode(string ticketCode)
{
	this->_ticketCode = ticketCode;
	return this->ticketCode();
}

string Ticket::ticketTitle(int num)
{
	switch(num){
		case 1: return this->_ticketTitle1;
		case 2: return this->_ticketTitle2;
		case 3: return this->_ticketTitle3;
		case 4: return this->_ticketTitle4;
		case 5: return this->_ticketTitle5;
	}
	return "";
}

string Ticket::ticketTitle(int num, string value)
{
	switch(num){
		case 1: 
			this->_ticketTitle1 = value; 
			break;
		case 2: 
			this->_ticketTitle2 = value; 
			break;
		case 3: 
			this->_ticketTitle3 = value; 
			break;
		case 4: 
			this->_ticketTitle4 = value; 
			break;
		case 5: 
			this->_ticketTitle5 = value; 
			break;
	}
	return this->ticketTitle(num);
}

string Ticket::ticketRelation(int num)
{
	switch(num){
		case 1: return this->_ticketRelation1;
		case 2: return this->_ticketRelation2;
		case 3: return this->_ticketRelation3;
		case 4: return this->_ticketRelation4;
		case 5: return this->_ticketRelation5;
	}
	return "";
}

string Ticket::ticketRelation(int num, string value)
{
	switch(num){
		case 1: this->_ticketRelation1 = value; break;
		case 2: this->_ticketRelation2 = value; break;
		case 3: this->_ticketRelation3 = value; break;
		case 4: this->_ticketRelation4 = value; break;
		case 5: this->_ticketRelation5 = value; break;
	}
	return this->ticketRelation(num);
}

vector<string> Ticket::ticketRelations(int num)
{
	return this->_split(this->ticketRelation(num), '_');
}