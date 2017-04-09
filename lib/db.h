#ifndef _DB_H_
#define _DB_H_

#include <iostream>
#include <vector>
#include <map>
#include <mysql/mysql.h>

using namespace std;

class Db 
{
	protected:
		string _host;
		string _user;
		string _pass;
		string _port;
		string _db;
		MYSQL* _con;

		bool _query(const char* query);
		MYSQL_RES* _storeResult();
		int _numFields(MYSQL_RES* result);
		MYSQL_ROW _fetchRow(MYSQL_RES* result);
		void _freeResult(MYSQL_RES* result);

	public:
		Db(string host, string user, string pass, string db);
		Db(string host, string user, string pass, string db, string port);
		bool connect();
		void close();
		string error();
		bool query(const char* query, vector<MYSQL_ROW>& results);

};

#endif
