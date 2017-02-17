#include<bits\stdc++.h>
#include"Task.h"
using namespace std;

#pragma once
class ToDo
{
private:
	
	struct Node 
	{
		Task data;
		Node *next=NULL;
		Node *pre = NULL;
	};
	
	int count;
	Node *head;
	Node *tail;

   void	addfirst(Task t);

   void addlast(Task t);

public:
	
	ToDo();

	~ToDo();
	
	void insert(Task t);     //insert in order

	void load();
	
	void display();
	
	void save();

	void clear();

	Task removeHead();

	Task removeTail();

	Task removeFromIndex(int index);

	Task removeItem(Task t);

	void removeWithPredicate(bool(*predicate)(Task& item));
	
	void Sort(bool(*comp)(Task item1, Task item2), int order);

	bool orderByDuration(Task task1, Task task2);

	void Merge(ToDo &list1, ToDo &list2);
};