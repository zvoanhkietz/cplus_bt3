#include "db.h"

Db::Db(string host, string user, string pass, string db)
{
	this->_host = host;
	this->_user = user;
	this->_pass = pass;
	this->_db 	= db;
	this->_port = "3306";
	this->_con = mysql_init(NULL);
}

Db::Db(string host, string user, string pass, string db, string port)
{
	this->_host = host;
	this->_user = user;
	this->_pass = pass;
	this->_db 	= db;
	this->_port = port;
	this->_con = mysql_init(NULL);
}

bool Db::connect()
{
	MYSQL* con = mysql_real_connect( 
		this->_con, 
		this->_host.c_str(), 
		this->_user.c_str(), 
		this->_pass.c_str(), 
		this->_db.c_str(), 
		0, NULL, 0);
	if (!con) {
      return false;
  	}  
	return true;
}

string Db::error()
{
	return mysql_error(this->_con);
}

void Db::close()
{
	return mysql_close(this->_con);
}

bool Db::query(const char* query, vector<MYSQL_ROW>& results)
{
	// connect
	if(!this->connect()){
		cout << this->error() << endl;
		this->close();
		return false;
	}

	this->_query(query);
	MYSQL_RES *result = this->_storeResult();
	if (result != NULL){
		MYSQL_ROW row;
		while ((row = this->_fetchRow(result))){
			results.push_back(row);
		}
		this->_freeResult(result);
		return true;
	}
	return false;
}

bool Db::_query(const char* query)
{
	return mysql_query(this->_con, query);
}

MYSQL_RES* Db::_storeResult()
{
	return mysql_store_result(this->_con);
}

int Db::_numFields(MYSQL_RES* result)
{
	return mysql_num_fields(result);
}

MYSQL_ROW Db::_fetchRow(MYSQL_RES* result)
{
	return mysql_fetch_row(result);
}

void Db::_freeResult(MYSQL_RES* result)
{
	return mysql_free_result(result);
}