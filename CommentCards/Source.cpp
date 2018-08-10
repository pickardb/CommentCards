//File Operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int enterCards (){
	//TODO When prompting for date, give prompt to make one word
	//TODO Make some fancy user UI for prompts
	
	//Open file for reading and writing
	fstream testfile;
	string line;
	testfile.open("Cards.txt");
	testfile << "Comment Cards:\n";
	testfile.close();
	system("pause");
	
	//Prompt the user for a number of cards to be entered
	int entries;
	cout<<"How many cards are you entering?:";
	cin>>entries;
	cin.ignore();

	//Open the card storage file and append to the end of the file
	testfile.open("Cards.txt", std::ios_base::app);

	//Get the data from the user for each section of the comment card
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

	//If any values are not filled out, replace with "null"
	if(date==""){date = "null";}
	if(server==""){server = "null";}
	if(food==""){food = "null";}
	if(drinks==""){drinks = "null";}
	if(service==""){service = "null";}
	if(value==""){value = "null";}
	if(country==""){country = "null";}
	if(comment==""){comment = "null";}

	//Write the data to the file in one continuous line
	testfile << date + " " + server + " " + food + " " + drinks + " " + service + " " + value + " " + country + " " + comment + "\n";
	}
	
	testfile.close();
	system("pause");
	return 0;
}

int getStats (string filename){
	/*STATS NEEDED*/
	//Food
	//Drink
	//Service
	//Value
	//Vibe
	//How many for each server
	//Visiting From
	//Recommend us?
	//Time of visit
	//Comment

	string commentFill;
	string cardsFill;
	string garbage;
	string date;
	string server;
	string food;
	string drinks;
	string service;
	string value;
	string country;
	string comment;

	ifstream statsfile;
	statsfile.open("Cards.txt");
	statsfile >> commentFill >> cardsFill;
	cout<<commentFill<<cardsFill<<endl;
	statsfile>>date>>server>>food>>drinks>>service>>value>>country>>comment;
	cout << date<<server<<food<<drinks<<service<<value<<country<<comment;
	//TODO Need to implement system to read multi word comments

	
	statsfile.close();
	system("pause");
	return 0;
}

int main () {
	
	enterCards();
	getStats("Cards.txt");

	return 0;
}
