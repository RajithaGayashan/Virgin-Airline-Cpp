#include<iostream>
#include <fstream> 
using namespace std;
int n,seat,aSeat;
char fNumber[10];
char dAirport[20];
char aAirport[20];

int main(){
std::ofstream outfile ("flight.txt");
//outfile << "my text here!" << std::endl;
cout<<outfile;
outfile.close();

	cout<<"~~~~~~ Welcome to Virgin Airline ~~~~~~~"<<endl;
	cout<<"''''':MAIN MANU:'''''"<<endl; 
	cout<<"Enter departure airport :-";
	cin>>dAirport;
	cout<<"Enter arrival airport :-";
	cin>>aAirport;
	
	
   int d;
   int m;
   int y;
   cout<<"enter date and / "<<endl;
   std::cin >> d; // read the day
   if ( std::cin.get() != '/' ) // make sure there is a slash between DD and MM
   {
      std::cout << "You entered wrong format/\n";
      return 1;
   }
    std::cin >> m; // read the month
   if ( std::cin.get() != '/' ) // make sure there is a slash between MM and YYYY
   {
      std::cout << "You entered wrong format /\n";
      return 1;
   }
   std::cin >> y; // read the year
   std::cout << "input date: " << d << "/" << m << "/" << y << "\n";

	switch(n){
		case 1:
			cout<<"~~~Display available flights~~~"<<endl;	
			if(aSeat>0){
//				cout<<"Flight number - "<<flightnumber<<endl;
//				cout<<"departure date and time - "<<datetime<<endl;
//				cout<<"departure airport code - "<<dairportcode<<endl;
//				cout<<"arrival airport code - "<<aairportcode<<endl;
//				cout<<"Number of seat available - "<<aSeat<<endl;
//				
				
			}	
		case 2:
			cout<<"~~~View flight~~~"<<endl;
			cout<<"Enter flight number :- ";
			cin>>fNumber;
//			if(flight==true){
//				cout<<aSeat<<endl;
//				cout<<dairport<<endl;
//				cout<<aairport<<endl;
//				cout<<
//			}
//					
		case 3:
			cout<<"~~~Seat availability~~~"<<endl;		
			cout<<"Enter flight number :- ";
			cin>>fNumber;
			cout<<"do you want number of seats? -: ";
			cin>>seat;
			if(seat<=aSeat){
				cout<<"success !"<<endl;
				aSeat=aSeat-seat;
			}
			else{
				cout<<"This flight is full"<<endl;
			}
		case 4:
			cout<<"~~~Seat booling~~~"<<endl;		
		case 5:
			break;
		case 6:
			cout<<"Display available flights"<<endl;		
		
	
	
	}

}
