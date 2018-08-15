//File Operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int numCards=0;


int enterCards (){
	//TODO When prompting for date, give prompt to make one word
	//TODO Make some fancy user UI for prompts
	
	//Open file for reading and writing
	fstream testfile;
	string temp;
	
	testfile.open("Cards.txt");
	testfile >> temp;
	if(temp == ""){
		testfile << "Comment Cards: 0\n";
	}
	else{
		testfile >> temp >> temp;
		numCards = std::stoi(temp);
	}
	printf("There are %d cards saved\n",numCards);
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
	string time;
	string server;
	string food;
	string drinks;
	string service;
	string value;
	string vibe;
	string country;
	string comment;

	for(int i = 0; i<entries; i++){
	cout<<"Date:";
	getline(cin,date);
	cout<<"Time (Hour only and AM/PM):";
	getline(cin,time);
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
	cout << "Vibe (1-4):";
	getline(cin,vibe);
	cout << "Country:";
	getline(cin,country);
	cout << "Comment:";
	getline(cin,comment);
	cout<<"\n";

	//If any values are not filled out, replace with "null"
	if(date==""){date = "null";}
	if(time==""){time = "null";}
	if(server==""){server = "null";}
	if(food==""){food = "null";}
	if(drinks==""){drinks = "null";}
	if(service==""){service = "null";}
	if(value==""){value = "null";}
	if(vibe==""){vibe = "null";}
	if(country==""){country = "null";}
	if(comment==""){comment = "null";}

	//Write the data to the file in one continuous line
	testfile << "Date: " + date + " Time: " +time + " Server: " + server + " Food: " + food + " Drinks: " + drinks + " Service: " + service + " Value: " + value + " Vibe: " + vibe + " Country: " + country + " Comment: " + comment + " END \n";
	
	//Add to the number of cards
	//Done every loop in case user closes program before all cards are entered
	numCards++;
	//Close and re-open the file to go back to the start of the file
	testfile.close();
	testfile.open("Cards.txt");
	testfile << "Comment Cards: " << numCards;
	//Close and re-open the file for appending
	testfile.close();
	testfile.open("Cards.txt", std::ios_base::app);
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

	//Variable to put strings that don't contain data
	string garbage;
	//Variable used when iterating through multiple word strings
	string temp;
	//Variables to store data form the cards
	string date;
	string time;
	string server;
	string food;
	string drinks;
	string service;
	string value;
	string vibe;
	string country;
	string comment;

	ifstream readfile;
	readfile.open("Cards.txt");
	readfile >> garbage >> garbage >> numCards;
	
	printf("There are %d cards in the system\n",numCards);

	for(int i = 0; i<numCards;i++){
		
		//Reset the temp variable
		temp = "";
		
		//Ignore "Date: " and take in the first word of the date
		readfile>>garbage>>date;
		
		//Take in all words until we find "Time: ", and add all those words to the end of the date string
		while(temp != "Time:"){
			date+=(" " +temp);
			readfile>>temp;
		}
		
		//Collect all the single word data
		readfile>>time>>garbage>>server>>garbage>>food>>garbage>>drinks>>garbage>>service>>garbage>>value>>garbage>>vibe>>garbage>>country>>garbage>>comment;
		
		//Read all the words of the multi word comment and add it to the comment string
		readfile>>temp;
		while((temp != "END")){
			comment+=(" "+ temp);
			readfile>>temp;
		}		
		
		//Print the data from each comment card
		cout<<" "<<date<<" "<<time<<" "<<server<<" "<<food<<" "<<drinks<<" "<<service<<" "<<value<<" "<<vibe<<" "<<country<<" "<<comment<<" \n";
	}

	readfile.close();
	system("pause");
	return 0;
}

int main () {
	
	enterCards();
	getStats("Cards.txt");

	return 0;
}
