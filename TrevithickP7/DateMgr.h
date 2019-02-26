//James Trevithick				jtrevithick2@cnm.edu				TrevithickP7

#include <string>
#include<iostream>
#include"Date.h"
#include <vector>
#include <sstream>
#include <array>
using namespace std;
class DateMgr
{
public:
	DateMgr();
	bool bReady;
	void Menu();
	void AskUser(string &filename);
	void Header();
	void GoodBye();
	bool IsReady();
private:
	Date mYDate[15];
	int total;
	vector<Date> found;
	Date findD;
	void ReadFile();
	string filename;
	vector<string> split(const string &s, char delim);
	void ChronoOrder();
	void Occurance();
	void SearchDate();
	void SearchEvent();
};

