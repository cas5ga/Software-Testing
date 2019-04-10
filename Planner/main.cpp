#include <iostream>
#include <fstream>
#include <string>
#include "Planner_Classes.h"
#include "inputValidation.h"
#include "gtest/gtest.h"
#include "GoogleTesting.h"

using namespace std;

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

TEST(CalendarMonth0Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(0).getNumDays() > 0)){
        cout <<"LOOK AT ME" << endl;
        cout << testCalendar.getYear(2000).getMonth(0).getNumDays() << endl;
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth13Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(13).getNumDays() > 0 && testCalendar.getYear(2000).getMonth(13).getNumDays() < 32)){
        //this if statement and clause is due to the bunk values typically read in at whatever memory address occurs after our last month.
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if((testCalendar.getYear(2000).getMonth(1).getNumDays() > 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth11Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if((testCalendar.getYear(2000).getMonth(11).getNumDays() > 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if((testCalendar.getYear(2000).getMonth(2).getNumDays() > 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth12Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if((testCalendar.getYear(2000).getMonth(12).getNumDays() > 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth6Test, makeCalendar){


    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if((testCalendar.getYear(2000).getMonth(6).getNumDays() > 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

TEST(Calendar1969Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    if(!initializeCalendar(testCalendar, 1969, 1969)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(Calendar1970Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    if(initializeCalendar(testCalendar, 1970, 1970)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(Calendar1971Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    if(initializeCalendar(testCalendar, 1971, 1971)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(Calendar2000Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    if(initializeCalendar(testCalendar, 2000, 2000)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(Calendar2029Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    if(initializeCalendar(testCalendar, 2029, 2029)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(Calendar2030Test, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    if(initializeCalendar(testCalendar, 2030, 2030)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(Calendar2031Test, makeCalendar){


    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    if(!initializeCalendar(testCalendar, 2031, 2031)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

TEST(CalendarMonth1_32DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 32)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_31DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if((testCalendar.getYear(2000).getMonth(1).getNumDays() == 31)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_30DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 30)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_29DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 29)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_28DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 28)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_27DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 27)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_15DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 15)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_2DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 2)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_1DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 1)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_0DaysTest_LY, makeCalendar){




    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(1).getNumDays() == 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

TEST(CalendarMonth1_32DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 32)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_31DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if((testCalendar.getYear(1999).getMonth(1).getNumDays() == 31)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_30DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 30)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_29DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 29)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_28DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 28)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_27DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 27)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_15DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 15)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_2DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 2)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_1DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 1)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth1_0DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(1).getNumDays() == 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

TEST(CalendarMonth2_32DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 32)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_31DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 31)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_30DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 30)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_29DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if((testCalendar.getYear(2000).getMonth(2).getNumDays() == 29)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_28DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 28)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_27DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 27)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_15DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 15)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_2DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 2)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_1DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 1)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_0DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(2).getNumDays() == 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

TEST(CalendarMonth2_32DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 32)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_31DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 31)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_30DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 30)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_29DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 29)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_28DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if((testCalendar.getYear(1999).getMonth(2).getNumDays() == 28)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_27DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 27)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_15DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 15)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_2DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 2)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_1DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 1)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth2_0DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(2).getNumDays() == 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

//DONE
TEST(CalendarMonth4_32DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 32)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_31DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 31)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_30DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if((testCalendar.getYear(1999).getMonth(4).getNumDays() == 30)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_29DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 29)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_28DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 28)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_27DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 27)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_15DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 15)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_2DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 2)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_1DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 1)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_0DaysTest_NLY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

//DONE
TEST(CalendarMonth4_32DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 32)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_31DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 1999, 1999);
    if(!(testCalendar.getYear(1999).getMonth(4).getNumDays() == 31)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_30DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if((testCalendar.getYear(2000).getMonth(4).getNumDays() == 30)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_29DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(4).getNumDays() == 29)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_28DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(4).getNumDays() == 28)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_27DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(4).getNumDays() == 28)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_15DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(4).getNumDays() == 15)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_2DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(4).getNumDays() == 2)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_1DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(4).getNumDays() == 1)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(CalendarMonth4_0DaysTest_LY, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;

    //These tests are "testing for failure" if the year is outside the bounds of 1970 and 2030.

    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    if(!(testCalendar.getYear(2000).getMonth(4).getNumDays() == 0)){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

TEST(EventNameTest, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;


    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    testCalendar.getYear(2000).getMonth(1).getDay(1).createEvent("Testing1", "Testing2", "Testing3");

    //creates an event with the name Testing1, the Time Testing2, and the Description Testing3.
    //Setting all 3 at once because that's the way the function works.


    if(testCalendar.getYear(2000).getMonth(1).getDay(1).getSpecificEvent(0).getName() == "Testing1"){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(EventTimeTest, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;


    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    testCalendar.getYear(2000).getMonth(1).getDay(1).createEvent("Testing1", "Testing2", "Testing3");

    //creates an event with the name Testing1, the Time Testing2, and the Description Testing3.
    //Setting all 3 at once because that's the way the function works.


    if(testCalendar.getYear(2000).getMonth(1).getDay(1).getSpecificEvent(0).getTime() == "Testing2"){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}
TEST(EventDescriptionTest, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;


    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    testCalendar.getYear(2000).getMonth(1).getDay(1).createEvent("Testing1", "Testing2", "Testing3");

    //creates an event with the name Testing1, the Time Testing2, and the Description Testing3.
    //Setting all 3 at once because that's the way the function works.


    if(testCalendar.getYear(2000).getMonth(1).getDay(1).getSpecificEvent(0).getDescription() == "Testing3"){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}

TEST(EventViewingTest, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;


    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    testCalendar.getYear(2000).getMonth(1).getDay(1).createEvent("Testing1", "Testing2", "Testing3");

    string tempString = viewEvent(testCalendar, 2000, 1, 1);

    //creates an event with the name Testing1, the Time Testing2, and the Description Testing3.
    //Setting all 3 at once because that's the way the function works.


    string correctString = "\nEvent ID: 1\nEvent Name: Testing1\nEvent Time: Testing2\nEvent Description: Testing3";

    if(tempString == correctString){
        testResult1 = true;
    }


    EXPECT_EQ(testResult1, testResult2);

}
TEST(EventDeletionTest, makeCalendar){
    bool testResult1 = false;
    bool testResult2 = true;


    Calendar testCalendar;
    initializeCalendar(testCalendar, 2000, 2000);
    testCalendar.getYear(2000).getMonth(1).getDay(1).createEvent("Testing1", "Testing2", "Testing3");

    deleteEvent(testCalendar, 2000, 1, 1, 1);
    string tempString = viewEvent(testCalendar, 2000, 1, 1);
    //creates an event with the name Testing1, the Time Testing2, and the Description Testing3.
    //Setting all 3 at once because that's the way the function works.

    //In this function I try to view the event after I delete it, and if it doesn't equal the "correctString" then it's deleted properly.



    string correctString = "\nEvent ID: 1\nEvent Name: Testing1\nEvent Time: Testing2\nEvent Description: Testing3";

    if(tempString != correctString){
        testResult1 = true;
    }
    EXPECT_EQ(testResult1, testResult2);

}


//calendar.getYear(inputYear).getMonth(inputMonth).getDay(inputDay).getNumEvents()

int main(int argc, char* argv[]){
    /*
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
    */
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



/*
 * Change the planner to use one function to make an event.
 * Make a class called "calendar" that contains years, each year
 * contains months, and each month contains days, that contain events.
 * Use some function structure to define everything.
 * Then, iterate through this structure to search for particular events.
 */
