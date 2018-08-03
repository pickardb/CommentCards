//File Operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	fstream testfile;
	string line;
	testfile.open("Cards.txt");
	testfile << "Comment Cards:\n";
	testfile.close();
	system("pause");

	int entries;
	cout<<"How many cards are you entering?:";
	cin>>entries;
	cin.ignore();

	testfile.open("Cards.txt", std::ios_base::app);
	string date;
	string server;
	string food;
	string drinks;
	string service;
	string value;
	string country;
	string comment;
	for(int i = 0; i<entries; i++){
	cout<<"Date:";
	getline(cin,date);
	cout << "Server:";
	getline(cin,server);
	cout << "Food (1-4):";
	getline(cin,food);
	cout << "Drinks (1-4):";
	getline(cin,drinks);
	cout << "Service (1-4):";
	getline(cin,service);
	cout << "Value (1-4):";
	getline(cin,value);
	cout << "Country:";
	getline(cin,country);
	cout << "Comment:";
	getline(cin,comment);
	cout<<"\n";

	if(date==""){date = "null";}
	if(server==""){server = "null";}
	if(food==""){food = "null";}
	if(drinks==""){drinks = "null";}
	if(service==""){service = "null";}
	if(value==""){value = "null";}
	if(country==""){country = "null";}
	if(comment==""){comment = "null";}

	testfile << date + " " + server + " " + food + " " + drinks + " " + service + " " + value + " " + country + " " + comment + "\n";
	}
	
	testfile.close();
	system("pause");
	return 0;
}
