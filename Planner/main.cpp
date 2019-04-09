#include <iostream>
#include <fstream>
#include <string>
#include "Planner_Classes.h"
#include "inputValidation.h"

using namespace std;

void readFile(){
//gonna read the file


}

void writeFile(){
//gonna write a file


}

void makeEvent(Calendar &calendar){
	int inputDay = 1;
	int inputMonth = 1;
	int inputYear = 1;
	int numDays = 1;
	//Year classInputYear;
	//Month classInputMonth;
	//Day classInputDay;


	cout<<"Please enter the year of the event: "<<endl;
	inputYear = inRange(calendar.getStartYear(),calendar.getEndYear()); //This takes the start year and the end year of the calendar and uses those as endpoints to
	//accept input from the user.
	cout<<endl;

	cout<<"Please enter the month of the event: "<<endl;
	inputMonth = inRange(1, 12);
	cout<<"inputMonth: "<<inputMonth<<endl;
	cout<<endl;


	cout<<"Please enter the day of the event: "<<endl;

	numDays = calendar.getYear(inputYear).getMonth(inputMonth).getNumDays();
//	cout<<"successfully computed numDays"<<endl;
	inputDay = inRange(0, numDays);
	cout<<endl;

	//this is the "event" we're working with.
	//pass in parameters to createEvent to create the event.
	//calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).createEvent();

    cout << &calendar << endl;
    cout << &calendar.getYear(inputYear) << endl;
    cout << &calendar.getYear(inputYear).getMonth(inputMonth) << endl;
    cout << &calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay) << endl;
	calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).createEvent();



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

void viewEvent(Calendar calendar){
	int inputDay = 1;
	int inputMonth = 1;
	int inputYear = 1;
	int daysInMonth = 1;
	string eventName = "debug";
	string eventTime = "debug";
	string eventDescription = "debug";

	cout<<"Please indicate the day in which you want to search for events"<<endl;
	cout<<"Please enter the year: ";
	inputYear = inRange(calendar.getStartYear(),calendar.getEndYear());

	cout<<"Please enter the month: ";
	inputMonth = inRange(0,13);

	if(inputMonth == 2 && calendar.getYear(inputYear).getLeapYear()){
		daysInMonth = 29;
	}
	else if(inputMonth == 2){
		daysInMonth = 28;
	}
	else if(inputMonth == 4 || inputMonth == 6 || inputMonth == 9 || inputMonth == 11){
		daysInMonth = 30;
	}
	else{
		daysInMonth = 31;
	}

	cout<<"Please enter the day: ";
	inputDay = inRange(0, daysInMonth+1);

	if(calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getNumEvents() == 0){
		cout<<"You have no events scheduled for the given day!"<<endl;
	}


	else{
		for(int i= 0; i < calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getNumEvents(); i++){
			eventName = calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getEvents()[i].getName();
			eventTime = calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getEvents()[i].getTime();
			eventDescription = calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getEvents()[i].getDescription();

			cout<<"Event "<<i+1<<": "<<endl;
			cout<<"Event Name: "<<eventName<<endl;
			cout<<"Event Time: "<<eventTime<<endl;
			cout<<"Event Description: "<<eventDescription<<endl;
		}

	}


}

void initializeCalendar(Calendar &calendar){

	int startYear = 0;
	int endYear = 0;

	cout<<"Please enter the first year of the Calendar" << endl;
	startYear = inRange(1969, 2030);
	cout<<endl;

	cout<<"Please enter the last year of the Calendar" << endl;
	endYear = inRange(startYear, 2031);
	cout<<endl;

	while(endYear <= startYear){
		cout<<"Please enter a later end year"<<endl;
		endYear = inRange(startYear, 2031);
		cout<<endl;
	}

	calendar.setYears(startYear, endYear);
	calendar.initializeYearList();

}

void menu(){

	cout<<"Menu:"<<endl;
    cout<<"1) Add Event"<<endl;
    cout<<"2) View Events"<<endl;
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
        cout<<"Please enter an option"<<endl;
        option = inRange(1,4);
        cout<<endl;

//        while(option < 1 || option > 4){
//            cout<<"Sorry, that number is not valid."<<endl;
//            cout<<"Please enter a valid response: "<<endl;
//            option= inRange(0,5);
//        }

        if(option == 1){
			makeEvent(calendar);
        }
        else if(option == 2){
			viewEvent(calendar);
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
