#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
#include"Task.h"

using namespace std;

Task::Task()
{
	name = "";
	description = "";
	priority = "";
	due_date = "";
	numberOfDays = "";
}

void Task::set_name(string a)
{
	name = a;
}

string Task::get_name()
{
	return name;
}

void Task::set_description(string a)
{
	description = a;
}

string Task::get_description()
{
	return description;
}

void Task::set_DueDate(string a)
{
	due_date = a;
}

string Task::get_DueDate()
{
	return due_date;
}

void Task::set_priority(string a)
{
	priority = a;
}

string Task::get_priority()
{
	return priority;
}

void Task::set_numberOfDays(string a)
{
	numberOfDays = a;
}

string Task::get_numberOfDays()
{
	return numberOfDays;
}

Task::Task(string a, string b, string c, string d, string e)
{
	name = a;
	description = b;
	priority = c;
	due_date = d;
	numberOfDays = e;
}

Task Task::make_task()
{
	Task newone;
//	cout << "Press any key\n";
	cin.ignore();
	cout << "Enter name of task : "; getline(cin, newone.name);
	
	cout << "Enter description of Task : "; getline(cin, newone.description);

	cout << "Enter task priority : "; cin >> newone.priority;
	cin.ignore();
	cout << "Enter due date : ";   getline(cin, newone.due_date);
	
	cout << "Enter number of days : "; cin >> newone.numberOfDays;
	
	return newone;
}

Task Task:: operator=(Task t)
{
	name = t.name;
	
	description = t.description;

	priority = t.priority;

	due_date = t.due_date;
	
	numberOfDays = t.numberOfDays;
	return *this;
}

bool Task:: operator==(Task t)
{
	if (this->get_name() == t.get_name() && this->get_numberOfDays() == t.get_numberOfDays() &&
		this->get_DueDate() == t.get_DueDate() && this->get_priority() == t.get_priority()
		&& this->get_description() == t.get_description())
		return true;
	return false;
}