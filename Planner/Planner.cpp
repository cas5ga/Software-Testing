#include <iostream>
#include <fstream>
#include <string>
#include "Planner_Classes.h"
#include "inputValidation.h"

using namespace std;

void readFile(){



}

void writeFile(){



}

void makeEvent(Calendar &calendar){
	int inputDay = 1;
	int inputMonth = 1;
	int inputYear = 1;
	int numDays = 1;
	//Year classInputYear;
	//Month classInputMonth;
	Day classInputDay;
	

	cout<<"Please enter the year of the event: ";
	inputYear = inRange(calendar.getStartYear(),calendar.getEndYear()); //This takes the start year and the end year of the calendar and uses those as endpoints to 
	//accept input from the user.

	cout<<"Please enter the month of the event: ";
	inputMonth = inRange(0, 13);
	
	cout<<"Please enter the day of the event: ";
	
	
	numDays = calendar.getYear(inputYear).getMonth(inputMonth).getNumDays();
	cout<<"successfully computed numDays"<<endl;
	inputDay = inRange(0, numDays);
	classInputDay = calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay);
	
	//this is the "event" we're working with.
	//pass in parameters to createEvent to create the event.
	//calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).createEvent();
	classInputDay.createEvent();
	
	
/*
	cout<<"Please enter the name of the event: ";
	getline(cin,name); //replace with get_line at a future date. 
	event.setName(name);
	
	cout<<"Please enter the time of the event: ";
	getline(cin,time);
    event.setTime(time);
    
    cout<<"Please enter the description of the event: ";
	getline(cin,description);
    event.setDescription(description);
    
    
    
    cout<<endl<<endl;
	*/
}

void initializeCalendar(Calendar &calendar){
	
	int startYear = 0;
	int endYear = 0;
	
	cout<<"Please enter the first year of the Calendar: " << endl;
	startYear = inRange(1969, 2030);
	cout<<endl;
	cout<<"Please enter the last year of the Calendar: " << endl;
	endYear = inRange(startYear, 2031);
	cout<<endl;
	
	while(endYear <= startYear){
		cout<<"Please enter a later end year: "<<endl;
		endYear = inRange(1969, 2031);
	}
	
	calendar.setYears(startYear, endYear);
	calendar.initializeYearList();
	
}

void initializeMonth(){
		
	
		
}

void initializeDay(){
	
	
	
}

void menu(){

    cout<<"1) Add Event"<<endl;
    cout<<"2) View Event"<<endl;
    cout<<"3) Delete Event"<<endl;
    cout<<"4) Quit"<<endl<<endl;

    return;
}

int main(){
    int option = 1;
    string name = "name";
    string time = "time";
    string description = "description";
    Event event;
    Calendar calendar;
    
    initializeCalendar(calendar);
    
    while(option != 4){

        menu();
        cout<<"Please enter the number associated with one of these options: ";
        option = inRange(0,5);

        while(option < 1 || option > 4){
            cout<<"Sorry, that number is not valid."<<endl;
            cout<<"Please enter a valid response: "<<endl;
            option= inRange(0,5);
        }

        if(option == 1){
			makeEvent(calendar);
        }
        else if(option == 2){

        }
        else if(option == 3){

        }

		cout<<endl;
    }

    return 0;
}



/*
 * Change the planner to use one function to make an event. 
 * Make a class called "calendar" that contains years, each year
 * contains months, and each month contains days, that contain events.
 * Use some function structure to define everything.
 * Then, iterate through this structure to search for particular events. 
 */
