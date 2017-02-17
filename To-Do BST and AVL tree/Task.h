#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;

#pragma  once       // acts as #define no differance 
class Task
{
private:

	string name;
	string description;
	string priority;
	string due_date;
	string numberOfDays;

public:

	Task();

	Task(string, string, string, string, string);

	/**********only setters & getters *********/
	void set_name(string a);
	string get_name();

	void set_description(string a);
	string get_description();

	void set_DueDate(string a);
	string get_DueDate();

	void set_priority(string a);
	string get_priority();

	void set_numberOfDays(string a);
	string get_numberOfDays();

	Task make_task();

	Task operator=(Task t);
	/********operator overloaging***********/
	friend ostream& operator<<(ostream &out, Task t)
	{
		out << "name : " << t.get_name() << endl << "description : " << t.get_description() << endl
			<< "priority : " << t.get_priority() << endl << "due date : " << t.get_DueDate() << endl
			<< "the number of days it takes : " << t.get_numberOfDays() << "\n______________________________" << endl;
		return out;
	}

	bool operator==(Task t);

};