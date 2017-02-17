#include<bits\stdc++.h>
#include"ToDo.h"
#include<algorithm>
#include <strstream>
#include<assert.h>
using namespace std;


ToDo::ToDo()
{
	count = 0;
	head = NULL;
	tail = NULL;
}


void ToDo::addfirst(Task t)
{

	Node * added = new Node;

	added->data = t;   
	
	added->next = head;
	
	added->pre = NULL;
	
	head = added;

}


void ToDo::addlast(Task t)
{
	Node * added = new Node;

	added->data = t;

	added->pre = tail;

	added->next = NULL;
	
	tail->next = added;

	tail = added;

}


ToDo::~ToDo()
{

	clear();
}


void ToDo::insert(Task t)
{
	Node * added = new Node;
	
	added->data = t;      //operator "=" defined

	Node *tmp = head;

	if (head == NULL)
	{
		head = added;
		tail = added;
		return;
	}

	while (tmp->next != NULL && tmp->data.get_priority() > added->data.get_priority())
	{
		tmp = tmp->next;

	}

	bool pass = false;
	
	if (tmp->pre == NULL&&tmp->next == NULL)
	{
		if (added->data.get_priority() > tmp->data.get_priority())
		{
			addfirst(t);
			pass = true;

		}
		else
		{
			addlast(t);
			pass = true;
		}
	}
	
	else if (tmp->pre==NULL)
	{
		addfirst(t);
		pass = true;
	}
	
	else if (tmp->next == NULL&&added->data.get_priority()<tmp->data.get_priority())
	{
		addlast(t);
		pass = true;
	}
	
	else
	{
		added->next = tmp;

		added->pre = tmp->pre;
		
		tmp->pre->next = added;

		tmp->pre = added;
	}

	
	if (pass)     
	{
		delete added;
	}
	count++;
}


void ToDo::save()
{
	fstream out("MyTasks.txt", ios::out | ios::trunc);
	Node *tmp = head;
	while (tmp != NULL)
	{
		out << tmp->data.get_name() << "|" << tmp->data.get_description() << "|"
			<< tmp->data.get_priority() << "|" << tmp->data.get_DueDate() << "|"
			<< tmp->data.get_numberOfDays() <<"|"<< '\n' ;
		tmp = tmp->next;

	}
	out.close();
	cout << "your Tasks successfully saved\n";
	
}


void ToDo::load()
{
	Task t;
	fstream in("MyTasks.txt", ios::in);
	stringstream ss;
	string record;
	string na, des, pri, du, dy;
	while (!in.eof())
	{
		getline(in, record);

		if (in.eof())
			break;
		ss << record;
		getline(ss, na, '|');
		getline(ss, des, '|');
		getline(ss, pri, '|');
		getline(ss, du, '|');
		getline(ss, dy, '|');

		t.set_name(na);
		t.set_description(des);
		t.set_priority(pri);
		t.set_numberOfDays(dy);
		t.set_DueDate(du);
	   this->insert(t);

	}

	in.close();
}


void ToDo::display()

{


	Node *tmp = head;

	while (tmp != NULL)

	{

		cout << tmp->data << endl;


		tmp = tmp->next;

	}

}


void ToDo:: clear()
{
	
	while (head!=NULL)
	{
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
	count = 0;
}


Task ToDo:: removeHead()
{
	Task val;
	Node *temp = head;
	assert(head != NULL);
		
	 if (head == tail)
	{
		delete head;
		head = tail = NULL;
		count--;
		return temp->data;
	}

	head = head->next;
	val = temp->data;
	delete temp;
	count--;
	cout << "Node deleted from head!\n";
	return val;
}


Task ToDo::removeTail()
{
	Task val;
	Node *temp;
	assert (head != NULL);
		
	 if (head == tail)
	{
		 val = tail->data;
		delete tail;
		tail = head = NULL;
		count--;
		return val;
	}
	else
	{
		temp = tail;
		tail = tail->pre;
		val = temp->data;
	}
	delete temp;
	count--;
	return val;
}


Task ToDo:: removeFromIndex(int index)
{
	index--;
	assert(index >= 0 && index < count);

	Task deleted;

	if (index == 0)
	{
		deleted = removeHead();
		return deleted;
	}
	else if (index == count - 1)
	{
		deleted = removeTail();
		return deleted;
	}
	else
	{
		Node *temp = head;
		for (int i = 0; i <= index; i++)
		{
			temp = temp->next;

		}
		deleted = temp->data;
		temp->pre->next = temp->next;
		temp->next->pre = temp->pre;
		delete temp;
		count--;
	}
	return deleted;
}


Task ToDo::removeItem(Task t)
{
	Task val;
	Node *tmp = head;
	for (int i = 1; i <= count; i++)
	{
		if (tmp->data == t)
		{
			val = removeFromIndex(i);
			return val;
		}
		tmp = tmp->next;
	}
	return val;
}


void ToDo:: removeWithPredicate(bool(*predicate)(Task& item))
{
	Node *tmp = head;
	Task item;
	while (tmp!=NULL)
	{
		item = tmp->data;
		tmp = tmp->next;
		if (predicate(item))
		{
			Task val=removeItem(item);
		}

	}
}


void ToDo:: Sort(bool(*comp)(Task item1, Task item2), int order)
{

	if (order == 0)
	{


		for (Node* i = head; i->next != NULL; i = i->next)
		{
			bool found = false;
			for (Node* j = head; j->next != NULL; j = j->next)
			{
				if (comp(j->data, j->next->data))
				{
					swap(j->data, j->next->data);
					found = true;
				}
			}

			if (!found)
				break;
		}
	}
	else
	{
		for (Node* i = head; i->next != NULL; i = i->next)
		{
			bool found = false;
			for (Node* j = head; j->next != NULL; j = j->next)
			{
				if (!comp(j->data, j->next->data))
				{
					swap(j->data, j->next->data);
					found = true;
				}
			}

			if (!found)
				break;
		}
	}

}


void ToDo::Merge(ToDo &list1, ToDo &list2)
{
	fstream out("MyTasks.txt", ios::out | ios::trunc);
	Node *t1, *t2;
	t1 = list1.head;
	t2 = list2.head;
	Node *tmp = new Node();
	Node *newnode = new Node();
	//int C1 = 0, C2 = 0;
	if (t1 == NULL) //lw list mnhom empty hay-sort el tania fel list el gdeda
	{
		while (t2 != NULL)
		{
			tmp->data = t2->data;
			t2 = t2->next;
			tmp = tmp->next;
		}
	}
	else if (t2 == NULL) //lw list mnhom empty hay-sort el tania fel list el gdeda
	{
		while (t1 != NULL)
		{
			tmp->data = t1->data;
			t1 = t1->next;
			tmp = tmp->next;
		}
	}
	else
	{
		
		for (t1 = list1.head; t1->next != NULL; t1->next)
		{
			for (t2 = list2.head; t2->next != NULL; t2->next)
			{
				if (t1 < t2)
				{
					newnode->data = t1->data;
					break;
				}
				else if (t2 < t1)
				{
					newnode->data = t2->data;
					break;
				}
				else
				{
					newnode->data = t1->data;
					newnode->next->data = t2->data;
				}
				//newnode = newnode->next;
			}
			out << newnode->data.get_name() << "|" << newnode->data.get_description() << "|"
				<< newnode->data.get_priority() << "|" << newnode->data.get_DueDate() << "|"
				<< newnode->data.get_numberOfDays() << "|" << '\n';
		}

		out.close();
	}
}

