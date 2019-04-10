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

//	Day(){}

//	Day(int d){
//		dayNum = d;
//	}

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
//    cout<<"Added"<<endl;
//    cout<<"Events in list: "<<getNumEvents()<<endl;
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

//	int getDayNum(){
//		return dayNum;
//	}


private:
	vector<Event> eventList;
	Event inputEvent;


};




class Month{

public:

	void setMonthDays(int monthNumber, bool leapYear){
//		cout << "Set month is getting called correctly." << endl;
//		cout << monthNumber << endl;
//		if(leapYear){
//			cout << "it's a leap year." << endl;
//		}
		switch(monthNumber){
			case 1:
//				cout<<"case 1"<<endl;
				setDays(31);
				break;
			case 2:
//				cout<<"case 2"<<endl;
				if(leapYear){
//					cout<<"leap year"<<endl;
					setDays(29);
				}
				else{
//					cout<<"not a leap year"<<endl;
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
//		cout << "is the fault after the loop ends?" << endl;
	}

	void setDays(int dayNumber){
//		cout << "is the error before the loop?" << endl;

		//dayList.insert(0, blankDay);

		for(int i = 0; i < dayNumber; i++){
			Day blankDay;
//			cout<<"Day Number: "<<blankDay.getDayNum()<<endl;
//			cout << "the error is in loop " << to_string(i+1) << endl;
//			cout<<".getDayNum() "<<dayList[i-1].getDayNum()<<endl;
			dayList.push_back(blankDay);
//			cout<<"after .push_back"<<endl;
			//dayList.insert(i, blankDay);
			//cout<<"length of dayList vector: "<<dayList.size()<<endl;

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
//	int monthNum;


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
//			cout<<"initializeMonthList runs " << i << " times" << endl;

			//sampleMonth.setMonth(i, leapYear);
			monthList.push_back(blankMonth);
//			cout << "After the monthlist push back" << endl;
			monthList[i].setMonthDays(i, leapYear);
//			cout<<"Days in Month: "<<monthList[i].getNumDays()<<endl;
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

