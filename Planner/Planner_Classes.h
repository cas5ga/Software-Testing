#ifndef Planner_Classes_H_
#define Planner_Classes_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Event{

public:

	void setName(string n){
		name = n;
	}

	void setTime(string t){
		time = t;
	}

	void setDescription(string d){
		description = d;
	}

	string getName(){
		return name;
	}

	string getTime(){
		return time;
	}

	string getDescription(){
		return description;
	}


private:
	string name, time, description;


};




class Day{

public:

    string setEventName(){
        string inputName = "debug";
        cout<<"Please enter the name of the event: ";
        cin.ignore();
        getline(cin,inputName);
        cout<<endl;
        return inputName;
    }

    string setEventTime(){
        string inputTime = "debug";
        cout<<"Please enter the time of the event: ";
        getline(cin,inputTime);
        cout<<endl;
        return inputTime;
    }

    string setEventDescription(){
        string inputDescription = "debug";
        cout<<"Please enter the description of the event: ";
        getline(cin,inputDescription);
        cout<<endl;
        return inputDescription;
    }

	void createEvent(string inputName, string inputTime, string inputDescription){

    inputEvent.setName(inputName);
    inputEvent.setTime(inputTime);
    inputEvent.setDescription(inputDescription);
    eventList.push_back(inputEvent);

	}

	int getNumEvents(){
		return eventList.size();
	}

	vector<Event>& getEvents(){
		return eventList;
	}

	Event getSpecificEvent(int s){
        return eventList[s];
	}


private:
	vector<Event> eventList;
	Event inputEvent;


};




class Month{

public:

	void setMonthDays(int monthNumber, bool leapYear){

		switch(monthNumber){
			case 1:
				setDays(31);
				break;
			case 2:
				if(leapYear){
					setDays(29);
				}
				else{
					setDays(28);
				}
				break;
			case 3: setDays(31);
				break;
			case 4: setDays(30);
				break;
			case 5: setDays(31);
				break;
			case 6: setDays(30);
				break;
			case 7: setDays(31);
				break;
			case 8: setDays(31);
				break;
			case 9: setDays(30);
				break;
			case 10: setDays(31);
				break;
			case 11: setDays(30);
				break;
			case 12: setDays(31);
				break;
		}

	}

	void setDays(int dayNumber){

		for(int i = 0; i < dayNumber; i++){
			Day blankDay;
			dayList.push_back(blankDay);
		}

	}

	int getNumDays(){
		return dayList.size();
	}



	Day& getDay(int dayNumber){
		return dayList[dayNumber];
	}


private:
	vector<Day> dayList;

};





class Year{

public:

	void setYear(int y){
		year = to_string(y);
	}

	string getYear(){
		return year;
	}

	Month& getMonth(int currentMonth){
		return monthList[currentMonth];
	}


	void setLeapYear(){
		if(stoi(year)%4 == 0){
			leapYear = true;
		}
		else{
			leapYear = false;
		}
	}

	bool getLeapYear(){
		return leapYear;
	}

	void initializeMonthList(){
		setLeapYear();
		for(int i = 0; i <= 12; i++){
			Month blankMonth;
			monthList.push_back(blankMonth);
			monthList[i].setMonthDays(i, leapYear);
		}
	}


private:
	vector<Month> monthList;
	bool leapYear;
	string year;

};




class Calendar{

public:

	void setYears(int startY, int endY){
		startYear = startY;
		endYear = endY;
	}

	int getStartYear(){
		return startYear;
	}

	int getEndYear(){
		return endYear;
	}

	Year& getYear(int currentYear){
		return yearList[currentYear-startYear];
	}

	void initializeYearList(){
		for(int i = startYear; i <= endYear; i++){
			Year sampleYear;
			sampleYear.setYear(i);
			yearList.push_back(sampleYear);
			yearList[i-startYear].initializeMonthList();
		}
	}


private:
	vector<Year> yearList;
	int startYear, endYear;

};

#endif

