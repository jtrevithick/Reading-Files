//James Trevithick				jtrevithick2@cnm.edu					TrevithickP7

#include "DateMgr.h"
#include<fstream>
#include <algorithm>
#include <sstream>
#include<vector>


DateMgr::DateMgr()
{
}

//http://www.cplusplus.com/reference/string/stoi/
void DateMgr::ReadFile()
{
	int count = 0;
	string line;
	ifstream input(filename.c_str());
	if (input.is_open())
	{
		while (getline(input, line))
		{
			if (line != "")
			{
				vector<string> values = split(line, ',');
				vector<string> dates = split(values[1], '/');
				mYDate[count].SetDate(stoi(dates[0]),stoi(dates[1]),stoi(dates[2]),values[0]);
				count++;
			}
		}
		input.close();
		total = count;
		bReady = true;

	}
	else
	{
		bReady = false;
	}
}

//http://ysonggit.github.io/coding/2014/12/16/split-a-string-using-c.html
vector<string> DateMgr::split(const string & s, char delim)
{
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}


void DateMgr::ChronoOrder()
{
	Date tmp;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 14; j > i; j--) {
			if (mYDate[j] << mYDate[j - 1]) {
				tmp = mYDate[j];
				mYDate[j] = mYDate[j - 1];
				mYDate[j - 1] = tmp;
			}
		}		
	}
}



void DateMgr::Occurance()
{
	Date tmp;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 14; j > i; j--) {
			if (mYDate[j] >> mYDate[j - 1]) {
				tmp = mYDate[j];
				mYDate[j] = mYDate[j - 1];
				mYDate[j - 1] = tmp;
			}
		}
	}

}

void DateMgr::SearchDate()
{
	for (Date d : mYDate) {
		if (d == findD) {
			found.push_back(d);
		}
	}
}

void DateMgr::SearchEvent()
{
	for (Date d : mYDate) {
		if (d + findD) {
			found.push_back(d);
		}
	}
}


void DateMgr::Menu()
{
	char options;
	string obj;//object to store the user input options
	do
	{
		//display menu to user
		cout << "\nPlease choose a menu option:"
			<< "\n1. Current list"
			<< "\n2. Search for event"
			<< "\n3. Search for the date. "
			<< "\n4. Events in chronological order "
			<< "\n5. Years in occurrence order."
			<< "\n6. Return to Main"
			<< "\n7. Exit Program";
		//get user options
		cout << "\n\nOptions: ";
		cin >> options;
		cin.ignore();
		//do switch options
		switch (options)
		{
		case '1':
			for (Date d : mYDate) {
				cout << d.GetFormattedDate() << endl;//gets the FormattedDate to display to the user in the file
			}
			cout <<"\nTotal in file: "<< total<<"\n";
			break;
		case'2':
			found.clear();//clear the found vector so it would not miss up the option
			cout << "\nEvent name? ";
			cin >> obj;
			findD.SetDesc(obj);//assisgn the describe in the obj
			SearchEvent();//Calls the SearchEvent in order to search for event name.
			for (Date d : found) {
				cout << d.GetFormattedDate() << endl;
			}
			cout << "\nTotal found: " << found.size()<<"\n";
			break;
		case'3':
			found.clear();//clear the found vector so it would not miss up the option
			cout << "\nWhat is the date(i.e 3/5/1989)? ";
			cin >> obj;
			findD.SetDate(stoi(split(obj, '/')[0]), stoi(split(obj, '/')[1]), stoi(split(obj, '/')[2]), "");//splits the / and the space
			SearchDate();//Calls the SearchDate method to it would search for the date
			for (Date d : found) {
				cout << d.GetFormattedDate() << endl;
			}
			cout << "\nTotal found: " << found.size()<<"\n";
			break;
		case'4':
			ChronoOrder();//calls the chronoorder method to order the Data in a chrono order
			for (Date d : mYDate) {
				cout << d.GetFormattedDate() << endl;	
			}
			break;
		case'5':
			Occurance();
			for (Date d : mYDate) {
				cout << d.GetFormattedDate() << endl;
			}
			break;
		case'6':
			exit;//exit program
			AskUser(filename);//return to the askuser method
			//exit program
			break;
		case'7':
			//exit program
			break;
		}
	} while (options != '7');
}

void DateMgr::AskUser(string & filename)
{
	string answer = "y";

	cout << "\nDo you want to manually write the files name? or use the default? y for manually, n for default. y/n:   ";
	getline(cin, answer);
	if (answer == "y")
	{

		cout << "\nWhat is the file name? ";
		getline(cin, filename);

	}
	else
	{
		this->filename = "Dates.txt";

	}
	ReadFile();//call the Readfile method after the user input their filename or use the default file.

	//check to see if there are any errors. if there is exit
	if (IsReady()) {

	}
	else {
		cout << "File not read.Try Again!\n";
		exit;//exit the program
		AskUser(filename);//return to ask the user for the file name
		
	}
	
}

void DateMgr::Header()
{
	cout << "James Trevithick\n"
		<< "CIS 2275-102"
		<< "\nTrevithickP7 Date Search.\n"
		<< "\nObjective: this program will read files. If the user search for a date and description that on the file."
		<< "\nthe program will give the dates and description to user\n";
}

void DateMgr::GoodBye()
{
	cout << "\nGoodBye Thank you for using the TrevithickP7 program. Hope to see you soon!\n";
}

bool DateMgr::IsReady()
{
	return bReady;
}



