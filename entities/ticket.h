#ifndef _TICKET_H_
#define _TICKET_H_

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Ticket
{
	protected:
		string _ticketCode;
		string _ticketRelation1;
		string _ticketTitle1;
		string _ticketRelation2;
		string _ticketTitle2;
		string _ticketRelation3;
		string _ticketTitle3;
		string _ticketRelation4;
		string _ticketTitle4;
		string _ticketRelation5;
		string _ticketTitle5;


		vector<string> _split(string input, char separator);
	public:
		Ticket();
		string ticketCode();
		string ticketCode(string ticketCode);
		string ticketTitle(int num);
		string ticketTitle(int num, string value);
		string ticketRelation(int num);
		string ticketRelation(int num, string value);
		vector<string> ticketRelations(int num);
};

#endif