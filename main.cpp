#include <iostream>
#include <fstream>
#include <string>
#include "Planner_Classes.h"
#include "inputValidation.h"

using namespace std;


//Matthew M. Boshears, Caleb A. Street, Nathan Lewis, Technically Payton
//4/10/2019
//Software Testing

void readFile(){
//gonna read the file


}

void writeFile(){
//gonna write a file


}

int eventInput(Calendar &calendar, int (&returnArray)[3]){
    int inputYear;

  	cout<<"Please enter the year of the event: "<<endl;
	inputYear = inRange(calendar.getStartYear(),calendar.getEndYear()); //This takes the start year and the end year of the calendar and uses those as endpoints to
	//accept input from the user.

	cout<<endl;

	int inputMonth;

	cout<<"Please enter the month of the event: "<<endl;
	inputMonth = inRange(1, 12);
	cout<<endl;

	int inputDay;
    int numDays;

	cout<<"Please enter the day of the event: "<<endl;

	numDays = calendar.getYear(inputYear).getMonth(inputMonth).getNumDays();
//	cout<<"successfully computed numDays"<<endl;
	inputDay = inRange(1, numDays);
	cout<<endl;



	returnArray[0] = inputYear;
	returnArray[1] = inputMonth;
	returnArray[2] = inputDay;

	return 0;
}


void makeEvent(Calendar &calendar, int inputYear, int inputMonth, int inputDay){

//    cout << &calendar << endl;
//    cout << &calendar.getYear(inputYear) << endl;
//    cout << &calendar.getYear(inputYear).getMonth(inputMonth) << endl;
//    cout << &calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay) << endl;

    string inputName = calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).setEventName();
    string inputTime = calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).setEventTime();
    string inputDescription = calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).setEventDescription();

	calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).createEvent(inputName, inputTime, inputDescription);



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

string viewEvent(Calendar &calendar, int inputYear, int inputMonth, int inputDay){
	string eventName = "debug";
	string eventTime = "debug";
	string eventDescription = "debug";

	string combinedOutput = "";

	if(calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getNumEvents() == 0){
		cout<<endl<<"You have no events scheduled for the given day!"<<endl;
	}


	else{
		for(int i= 0; i < calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getNumEvents(); i++){
            combinedOutput = combinedOutput + "\n" + "Event ID: " + to_string(i+1);
			combinedOutput = combinedOutput + "\n" + "Event Name: " + calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getEvents()[i].getName();
			combinedOutput = combinedOutput + "\n" + "Event Time: " + calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getEvents()[i].getTime();
			combinedOutput = combinedOutput + "\n" + "Event Description: " + calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getEvents()[i].getDescription();
            /*
			cout<<endl<<"Event ID: "<<i+1<<endl;
			cout<<"Event Name: "<<eventName<<endl;
			cout<<"Event Time: "<<eventTime<<endl;
			cout<<"Event Description: "<<eventDescription<<endl;
			*/
		}

	}

	return combinedOutput;

}

int getEventId(Calendar &calendar, int inputYear, int inputMonth, int inputDay){

    int eventID;
    cout << viewEvent(calendar, inputYear, inputMonth, inputDay) << endl << endl;
    cout << "Please enter the ID of the event that you would like to delete: " << endl;
    eventID = inRange(1, calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getNumEvents());

    return eventID;
}


void deleteEvent(Calendar &calendar, int inputYear, int inputMonth, int inputDay, int eventID){

    //viewEvent(calendar, inputYear, inputMonth, inputDay);



	if(calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getNumEvents() == 0){
		cout<<endl<<"You have no events scheduled for the given day!"<<endl;
	}
	else{
        calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getEvents().erase
        (calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getEvents().begin() + (eventID-1));
	}
}

void initializeCalendarInput(int (&inputValues)[2]){

    int startYear;
    int endYear;
    cout<<"Please enter the first year of the Calendar" << endl;
	startYear = inRange(1970, 2030);
	cout<<endl;

    cout<<"Please enter the last year of the Calendar" << endl;
	endYear = inRange(startYear, 2030);
	cout<<endl;

	while(endYear < startYear){
		cout<<"Please enter a later end year"<<endl;
		endYear = inRange(startYear, 2030);
		cout<<endl;
	}

    inputValues[0] = startYear;
    inputValues[1] = endYear;

    return;

}


int initializeCalendar(Calendar &calendar, int startYear, int endYear){
    if(startYear < 1970 || endYear > 2030){
        return 0;
    }
	calendar.setYears(startYear, endYear);
	calendar.initializeYearList();

	return 1;

}

void menu(){

	cout<<"Menu:"<<endl;
    cout<<"1) Add Event"<<endl;
    cout<<"2) View Events"<<endl;
    cout<<"3) Delete Event"<<endl;
    cout<<"4) Quit"<<endl<<endl;

    return;

}



//calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getNumEvents()

int main(int argc, char* argv[]){

    int option = 1;
    string name = "name";
    string time = "time";
    string description = "description";
    Event event;
    Calendar calendar;
    int inputArray[3];
    int inputValues[2];
    string outputString = "debug";
    int tempID = -1;

    initializeCalendarInput(inputValues);
    initializeCalendar(calendar, inputValues[0], inputValues[1]);

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
            eventInput(calendar, inputArray);
			makeEvent(calendar, inputArray[0], inputArray[1], inputArray[2]);
        }
        else if(option == 2){
            cout<<"Please indicate the day in which you want to search for events"<<endl;
            eventInput(calendar, inputArray);
			outputString = viewEvent(calendar, inputArray[0], inputArray[1], inputArray[2]);
			cout << outputString << endl;
        }
        else if(option == 3){
            cout<<"Please indicate the day in which you want to delete an event"<<endl<<endl;
            eventInput(calendar, inputArray);
            tempID = getEventId(calendar, inputArray[0], inputArray[1], inputArray[2]);
			deleteEvent(calendar, inputArray[0], inputArray[1], inputArray[2], tempID);
        }

		cout<<endl;
    }
}
