#include <iostream>
#include <vector>
#include <algorithm>

#include "lib/db.h"
#include "entities/ticket.h"
#include "entities/attraction.h"

using namespace std;

void mergeCodesUnique(vector<string>& v1, vector<string> v2)
{
	for(vector<string>::iterator it = v2.begin(); it != v2.end(); ++it){
		if(find(v1.begin(), v1.end(), (*it)) == v1.end()) {
			v1.push_back((*it));
		}
	}
}

Attraction findFirstAttrationByCode(string code)
{
	Db db("172.17.0.2", "vkiet", "123456", "ticket");
	Attraction result;
	if(!code.empty()){
		vector<MYSQL_ROW> rows;
		string strQuery = "SELECT * FROM attraction WHERE code='" + code + "'";
		if(db.query(strQuery.c_str(), rows)){
			for(vector<MYSQL_ROW>::iterator it = rows.begin(); it != rows.end(); ++it){
				MYSQL_ROW row = (*it);
				result.id(row[0]);
				result.code(row[1]);
				result.name(row[2]);
			}
		}
	}
	return 	result;
}

bool findTicketByCode(string ticketCode, vector<Ticket>& results, map<string, Attraction>& attractions)
{
	Db db("172.17.0.2", "vkiet", "123456", "ticket");

	results.clear();
	vector<MYSQL_ROW> rows;
	vector<string> attrCodes;

	if(db.query("SELECT * FROM ticket_detail", rows)){
		for(vector<MYSQL_ROW>::iterator it = rows.begin(); it != rows.end(); ++it){
			MYSQL_ROW row = (*it);
			Ticket ticket;
			ticket.ticketCode(row[1]);

			for(int i = 1; i <= 5; i++){
				ticket.ticketTitle(i, row[i + 1]);
				ticket.ticketRelation(i, row[i + 6]);

				// get list attraction code
				vector<string> codes = ticket.ticketRelations(i);
				mergeCodesUnique(attrCodes, codes);
			}
			results.push_back(ticket);
		}
	}

	// find attraction info
	for(vector<string>::iterator it = attrCodes.begin(); it != attrCodes.end(); ++it){
		string code = *it;
		Attraction attr = findFirstAttrationByCode(code);
		if(!attr.code().empty()){
			attractions[code] = attr;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	vector<Ticket> tickets;
	map<string, Attraction> attractions;
	if(findTicketByCode("12", tickets, attractions)){
		vector<Ticket>::iterator it = tickets.begin();
		while(it != tickets.end()){
			Ticket tk = (*it);
			cout << tk.ticketCode() << endl;
			for(int num = 1; num <= 5; num++){
				cout << "|__title=" << tk.ticketTitle(num) << endl;
				vector<string> codes = tk.ticketRelations(num);
				for(int i =0; i< codes.size(); i++){
					string code = codes[i];
					if(!code.empty()){
						Attraction attr = attractions[code];
						cout << "   |____id=" << attr.id() << " | code" << attr.code() << " | name=" << attr.name() << endl;
					}
				}
			}
			cout << endl;
			++it;
		}
	}
	return 0;
}