#include<bits\stdc++.h>
#include<fstream>
#include"Task.h"
#include"ToDo.h"
#include<iostream>

using namespace std;
 
int numberOfLists = 0;

bool orderByDuration(Task task1, Task task2) {
	return (task1.get_numberOfDays() < task2.get_numberOfDays());
}


bool orderByName(Task task1, Task task2) {
	return (task1.get_name() < task2.get_name());
}


bool orderByDueDate(Task task1, Task task2) {
	return (task1.get_DueDate() < task2.get_DueDate());
}


bool orderByPriority(Task task1, Task task2) {
	return (task1.get_priority() < task2.get_priority());
}


int project()
{
	cout << "1-> Add New List \n";
	cout << "2-> Edit list \n";
	cout << "3-> Merge two lists\n";
	int z;
	cin >> z;
	return z;
}

int start()
{
	cout << "1-> Load your Tasks\n";
	cout << "2-> Add new task\n";
	cout << "3-> Save your Tasks\n";
	cout << "4-> Display your Tasks\n";
	cout << "5-> Clear your task\n";
	cout << "6-> Delete task\n";
	cout << "7-> Exit from list\n";
	cout << "-> Enter your choice!: ";
	int x;
	cin >> x;
	return x;
}

int forgo()
{
	cout << "1:Go to main menu\n";
	cout << "2:Exit program\n";
	cout << "Enter your choice: ";
	int chos;
	cin >> chos;
	return chos;
}

void fixed()
{
	cout << "*************************\n";
	cout << "****      TO-DO     *****\n";
	cout << "****      LIST      *****\n";
	cout << "*************************\n";
}



int main()
{
	cout << "Your owen todo list\n\n";

	
	
	ToDo list;
    fi:
	int val = start();
	
	system("cls");
	
	


	
	 if (val == 1)
	{
		 list.load();
		 cout << "your data succefuly loaded\n";
		 cout << "1:Go to main menu\n";
		 cout << "2:Exit program\n";
		 cout << "Enter your chosse: ";
		 int sel;
		 cin >> sel;
		 if (sel == 1)
		 {
			 system("cls");
			 goto fi;
		 }
		 else
			 exit(0);
	}
	 else if (val == 2)
	 {
		 Task t;
		 t = t.make_task();
		 list.insert(t);
		 system("cls");
		 goto fi;
	 }
	 else if (val == 3)
	 {
		 list.save();
		 cout << "1:Go to main menu\n";
		 cout << "2:Exit program\n";
		 cout << "Enter your chosse: ";
		 int sel;
		 cin >> sel;
		 if (sel == 1)
		 {
			 system("cls");
			 goto fi;
		 }
		 else
			 exit(0);
		 goto fi;
	 }
	 else if (val == 4)
	 {
		 list.display();
		 cout << "1:Go to main menu\n";
		 cout << "2:Exit program\n";
		 cout << "Enter your chosse: ";
		 int sel;
		 cin >> sel;
		 if (sel == 1)
		 {
			 system("cls");
			 goto fi;
		 }
		 else
			 exit(0);
		 goto fi;
	 }
	 else if (val == 5)
	 {
		 list.clear();
		 cout << "Your tasks succufuly deleted\n\n";
		 cout << "1:Go to main menu\n";
		 cout << "2:Exit program\n\n";
		 cout << "->Enter your chosse: ";
		 int sel;
		 cin >> sel;
		 if (sel == 1)
		 {
			 system("cls");
			 goto fi;
		 }
		 else
			 exit(0);
		 goto fi;
	 }
	 else if (val == 6)
	 {
		 system("cls");
		 cout << "1-> delet first task\n";
		 cout << "2-> delet last task\n";
		 cout << "3-> delet from index\n";
		 cout << "4-> delet by name\n";
		 int num;
		 cin >> num;
       
	 }
	 else if (val == 7)
	 {

	 }

	 else if (val == 8)
	 {
		 exit(0);
	 }
	 
	return 0;
}



