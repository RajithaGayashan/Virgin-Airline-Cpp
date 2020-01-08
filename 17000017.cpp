#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main (){
  string array[100];
  string line; 
  int i=0,j=0,k=10;                        
  ifstream myfile ("Flights.txt"); 
  if (myfile.is_open()){            
    while (! myfile.eof()){
      getline (myfile,line);        
      cout << line <<  endl;            
      i++;	
	}
    while(k!=5){
		cout<<"1.Display available flights"<<endl;
		cout<<"2.View flight"<<endl;
		cout<<"3.Seat availability"<<endl;
		cout<<"4.Seat booking"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>k;
 	}

	int size =i;
	int start=i;
	while(j<=size){
		while(array[i]!="\n"){
			i++;
		}
		int end=i-1;
		//string arr[]=flight(array,start,end);
		i++;
	}
		
    myfile.close();      
  }
  else{
   cout << "Unable to open file"; 
  }
 
//  system("PAUSE");
//    
//       system("PAUSE");
//  
class flight{
	private string flightNumber;
	private string date;
	private string time;
	
};



return 0; 
}

