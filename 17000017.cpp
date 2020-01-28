#include <iostream>
#include<iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;
class Flight{
    private:
    string flightNumber,depLocation,depTime,ArrLocation;
    bool Eseat[60][6],Bseat[60][6];
    int allEseats,allBseats;
    void setSeatsFalse(){
        for(int i=0;i<60;i++){
            for(int j=0;j<6;j++){
                Eseat[i][j]=false;
                Bseat[i][j]=false;
            }
        }
    }

    public:
    string getFlightNumber(){
        return flightNumber;
    }
    Flight(string id,string deplocation,string deptime,string Arrlocation){
        flightNumber=id;
        depLocation=deplocation;
        depTime=deptime;
        ArrLocation=Arrlocation;
        allBseats=allEseats=0;
        setSeatsFalse();
        
    }
    
    void setValueForSeat(int row,char col,char cls){
        if(cls=='B'){
            int columnVal=((int)col-(int)'A');
            Bseat[row][columnVal]=true;
            allBseats++;
        }else if(cls=='E'){
            int columnVal=((int)col-(int)'A');
            Eseat[row][columnVal]=true;
            allEseats++;
        }
    }
    void displayAllDetails(){
      	cout<<"|   Flight id:                  -"<<flightNumber<<endl;
        cout<<"|   Departure Location:         -"<<depLocation<<endl;
        cout<<"|   Departure time:             -"<<depTime<<endl;
        cout<<"|   Arrival Location:           -"<<ArrLocation<<endl;
        cout<<"|   Number of seats in B class: -"<<allBseats<<endl;
        cout<<"|   Number of seats in E class: -"<<allEseats<<endl;
        cout<<"+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
		
        cout<<endl;
        cout<<endl;
    }
    void printAvailbleseat(){
        cout<<"B Class Availble seats : "<<endl;
        for (int i = 0; i < 60; i++){
            for (int j = 0; j < 6; j++){
                if(Bseat[i][j]){
                    char seat=(char)((int)'A'+j);
                    cout<<i<<seat<<"  ";

                }
            }
            
        }
        cout<<endl;
        cout<<"E Class Availble seats : "<<endl;
        for (int i = 0; i < 60; i++){
            for (int j = 0; j < 6; j++){
                if(Eseat[i][j]){
                    char seat=(char)((int)'A'+j);
                    cout<<i<<seat<<"  ";
                }
            }
            
        }
        cout<<endl<<endl<<endl;
        displayAllDetails();   
    }
    bool checkAvailability(int seats){
        if((allBseats+allEseats)>seats){
            return true;
        }else{
            return false;
        }
    }
    void bookSeat(char cls,int row,char col){

	    if(cls=='E'){
            int column=(int)col-(int)'A';
            if(Eseat[row][column]){
                Eseat[row][column]=true;
                cout<<"Your seat Booked"<<endl;	
				}else{
                cout<<"This seat already booked"<<endl;
            }
        }
        if(cls=='B'){
            int column=(int)col-(int)'A';
            if(Bseat[row][column]){
                Bseat[row][column]=true;
                cout<<"Your seat Booked"<<endl;	
				}else{
                cout<<"This seat already booked"<<endl;
            }
        }
        cout<<endl;
    	cout<<endl;
    }
};

int main(){
	string array[100];
    int i=0;
    int allFlights=0;
    ifstream file("Flights.txt");
	while(getline(file,array[i])){
        if(array[i]==""){
            allFlights++;
        }
        i++;
    }
    Flight *farray[allFlights];
    int j=0;
   for(int k=0;k<allFlights;k++){
        farray[k]=new Flight(array[j],array[j+2],array[j+1],array[j+3]);
        j=j+4;
        
        while(array[j]!=""){
            string stemp=array[j];
            int itemp=stemp.find(" ");
            stringstream s(stemp.substr(0,itemp));
            int row=0;
            s>>row;
            char cls=stemp[itemp+1];
            itemp+=3;
            while(stemp.length()>itemp){
                farray[k]->setValueForSeat(row,stemp[itemp],cls);
                itemp++;
            }

            j++;
        }
        j++;
	
    }
    while(1){
        char select;
        cout<<"~___Welcome to Virgin Airline___~"<<endl;
        cout<<"~``````````MAIN Menu``````````~"<<endl;
        cout<<"|   1)Display available flights|"<<endl;
        cout<<"|   2)View flight              |"<<endl;
        cout<<"|   3)Seat availability        |"<<endl;
        cout<<"|   4)Seat booking             |"<<endl;
        cout<<"|   5)Exit                     |"<<endl;
        cout<<"~------------------------------~"<<endl;
        cout << "Enter your Choice : ";
		cin>>select;
        string fid;
        int numberofseats,row,i;
        char col,cls;
        switch(select)
        {
        case '1':
            cout << "<<<<<<<<<< Flights available & Seats available>>>>>>>>>>"<< endl;
            for(i=0;i<allFlights;i++){
                farray[i]->displayAllDetails();
            }
            break;
        case '2':
            cout << "<<<<<<<<<<<<<<<<<< Flight Details >>>>>>>>>>>>>>>>>>>"<< endl;
            cout<<"Enter flight number : ";
            cin>>fid;
	         for (i = 0; i < allFlights; i++){
                if(farray[i]->getFlightNumber()==fid){
                    farray[i]->printAvailbleseat();
                    break;
                }
            }
            if(i==allFlights){
                cout<<"You entered invalid flight number!"<<endl;
                cout<<endl;
            }
            break;
        case '3':
            cout << "<<<<<<<<<<<<<<<<< Seat Availability >>>>>>>>>>>>>>>>>>>"<< endl;
            cout<<"Enter flight number : ";
            cin>>fid;
			for (i = 0; i < allFlights; i++){
                if(farray[i]->getFlightNumber()==fid){
                    farray[i]->printAvailbleseat();
                    break;
                }
            }
            if(i==allFlights){
                cout<<"You entered invalid flight number!"<<endl;
                cout<<endl;
                break;
            }
            cout<<"How many seats do you want : ";
            cin>>numberofseats;
            if(farray[i]->checkAvailability(numberofseats)){
                cout<<"You can buy"<<endl;
                cout<<endl;
            }else{
                cout<<"Sorry,we don't have this much of seats"<<endl;
                cout<<endl;
            }
            break;


        case '4':
            cout << "<<<<<<<<<<<<<<<< Seat Booking >>>>>>>>>>>>>>>>>>>"<< endl;
            cout<<"Enter flight number : ";
            cin>>fid;
			for (i = 0; i < allFlights; i++){
                if(farray[i]->getFlightNumber()==fid){
                    farray[i]->printAvailbleseat();
                    break;
                }
            }
            if(i==allFlights){
                cout<<"You entered invalid flight number!"<<endl;
                cout<<endl;
                break;
            }
            cout<<"Enter your flight class:(Please choice E or B)"<<endl;
            cout<<"E(Economy class)/B(Business class) : " ;
            cin>>cls;
            if(!(cls=='E'||cls=='B')){
                cout<<"You entered invalid flight class!"<<endl;
                cout<<endl;
                break;
            }
            cout<<"Enter row number: ";
            cin>>row;
            if(row>60){
                cout<<"You entered invalid seat row!"<<endl;
                cout<<endl;
                break;
            }
            cout<<"Enter column: ";
            cin>>col;
            if((int)col-(int)'A'<0||(int)col-(int)'A'>5){
                cout<<"You entered invalid seat colomn!"<<endl;
                cout<<endl;
			    break;
            }
			farray[i]->bookSeat(cls,row,col);


        case '5':
            exit(1);
        default:
             cout<<"You entered invalid input!"<<endl;
             cout<<endl;
            break;
        }

    }
}
