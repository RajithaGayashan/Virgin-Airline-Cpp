#include<iostream>
#include <fstream> 
using namespace std;
int seat,aSeat,i,k=10;
char fNumber[10];
char dAirport[20];
char aAirport[20];
char location[65];
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
	
	int h;
	int min;
	cout<<"enter time and : "<<endl;
	std::cin >> h; 
   		if ( std::cin.get() != ':' ) 
   		{
      		std::cout << "You entered wrong format/\n";
      		return 1;
   		}
    std::cin >> min; // read the year
    std::cout << "input time: " << h<< ":" << min<<endl;
			



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
	
	while(k!=5){
	cout<<"1.Display available flights"<<endl;
	cout<<"2.View flight"<<endl;
	cout<<"3.Seat availability"<<endl;
	cout<<"4.Seat booking"<<endl;
	cout<<"5.Exit"<<endl;
	cout<<"Enter your choice : ";
	cin>>k;
	switch(k){
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
			break;	
		case 2:
			cout<<"~~~View flight~~~"<<endl;
			cout<<"Enter flight number :- ";
			cin>>fNumber;
//			if(flight==true){
//				cout<<"Number of seat available- "<<aSeat<<endl;
//				cout<<"departure airport - "<<datetime<<endl;
//			    cout<<"arrival airport - "<<aairport<<endl;
//				cout<<"departure date and time - "<<datetime<<endl;
//			
//			}else{
				cout<<"No this flight "<<endl;
				
//          }
			break;		
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
			break;
		case 4:
			cout<<"~~~Seat booling~~~"<<endl;
			cout<<"Enter flight number :- ";
			cin>>fNumber;
			cout<<"Seat location :- ";
			cin>>location;
			
			for(i=1;i<=60;i++){
				for(char a='a'; a < 'a' +6; ++a){
    				cout <<i<<"-"<< a<<"\n";
				}
				cout<<endl;		
			}
			break;
		case 5:
			break;
		default:
			cout<<"Invaliad input"<<endl;
	}		
	}
}
