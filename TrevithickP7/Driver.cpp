//James Trevithick					jtrevithick2@cnm.edu							TrevithickP7

#include"Date.h"
#include"DateMgr.h"


int main()
{
	//Variables
	string filename;
	//Make an class object
	DateMgr dmgr;
	//call the methods from DateMgr class
	dmgr.Header();//calls the header method
	dmgr.AskUser(filename);//calls the askuser method and readfile and check the file.
	dmgr.Menu();//call the menu method
	dmgr.GoodBye();//call the goodbye method after the user exit the program.
	return 0;
}