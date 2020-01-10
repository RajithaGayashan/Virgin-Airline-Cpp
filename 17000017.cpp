#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class flight{
	 string flightNumber;
	 string date;
	 string time;
	 string depAirport;
	 string arrAirport;
	 bool ESeat[60][6];
	 bool BSeat[60][6];

	public:
		flight(string array[],int start,int end){
		flightNumber=array[start];
		cout<<flightNumber<<endl;
		string temp=array[start+1];
		cout<<temp;
		int i=0;
		while(temp[i]!=" "){
			this->depAirport=array[start+2];
			this->arrAirport=array[start+3];
		
			for(int i=1;i<=60;i++){
				for(int j=0;j<=5;j++){
					ESeat[i][j]=false;
					BSeat[i][j]=false;
					int i=start+4;
				}
			}
		}
	}	
};

int main (){
  string array[100];
  string line; 
  int i=0,j=0,k=10;                        
  ifstream myfile ("Flights.txt"); 
  if (myfile.is_open()){            
    while (! myfile.eof()){
      getline (myfile,line); 
	  array[i] = line;       
      //cout << line <<  endl;            
      i++;	
	}
    /*while(k!=5){
		cout<<"1.Display available flights"<<endl;
		cout<<"2.View flight"<<endl;
		cout<<"3.Seat availability"<<endl;
		cout<<"4.Seat booking"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your choice :";
		cin>>k;
 	}*/
 	
	int size=i;
	int i=0;
	while(j<=size){
		int start=i;
		while(array[i]!=""){
			i++;
		}
		int end=i-1;
		flight f1(array,start,end);
		i++;
		j = i;
	}
		
 //   myfile.close();      
  }
  else{
   cout << "Unable to open file"; 
  }
 
//  system("PAUSE");
//    
//       system("PAUSE");

	
	//class fight(array,start,end);
	
//  
return 0; 
}





