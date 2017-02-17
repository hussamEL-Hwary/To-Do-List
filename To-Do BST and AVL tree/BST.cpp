#include<bits\stdc++.h>
#include"Task.h"
#include"BST.h"
using namespace std;


BST::BST()
{
	root = NULL;
	lastincount = 0;
	lastdelcount = 0;
	lastsercoun = 0;
}


void BST::insert(Task &in)
{
	lastincount = 0;
	insert(root, in);
}


void BST::insert(Node * &n, Task &t)
{
	
	if (n == NULL)
	{
		n = new Node;
		n->data = t;
		n->left = NULL;
		n->right = NULL;
		
	}
	
	else if (t.get_name() <= n->data.get_name())
	{
		lastincount++;
		insert(n->left, t);
		
	}
	
	else
	{
		lastincount++;
		insert(n->right, t);
	}
}


void BST::search(string name)
{
	lastsercoun =0 ;
	search(root, name);
}


void BST:: search(Node* &n, string &val)
{
	if (n == NULL)
	{
		cout << "Task not found\n";

	}
	else if (val < n->data.get_name())
	{
		lastsercoun++;
		search(n->left, val);
	}
	else if (val>n->data.get_name())
	{
		lastsercoun++;
		search(n->right, val);
	}
	else
	{
		cout << n->data;
	}

}


Task BST::removeTopPriority()
{
	
	Task pr;
	pr.set_priority("-1");
	
	traverse(root , pr);
	
	remove(root, pr);
	
	return pr;

}


void BST:: traverse(Node* &r, Task &pr)
{
	if (r == NULL)
		return ;
	int x = atoi(r->data.get_priority().c_str());
	if (x > atoi(pr.get_priority().c_str()))
	{
		pr = r->data;
		
	}

	 traverse(r->left, pr);
     traverse(r->right, pr);

}


void BST::load()
{
	Task t;
	fstream in("mytasks.txt", ios::in);
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


void BST::save()
{

	fstream out("mytasks.txt", ios::out | ios::trunc);
	save(out, root);
	out.close();

}


void BST::save(fstream &out, Node* &n)
{
	if (n == NULL)
		return;
	out << n->data.get_name() << "|" << n->data.get_description() << "|"
		<< n->data.get_priority() << "|" << n->data.get_DueDate() << "|"
		<< n->data.get_numberOfDays() << "|" << '\n';

	save(out, n->left);
	save(out, n->right);
}


void BST::findall(vector<Task>& all, Node* &n)
{
	if (n == NULL)   return;
	else 
	all.push_back(n->data);

	findall(all, n->left);
	findall(all,n->right);
}


void BST::listOrderd()
{
	vector<Task>all;
	findall(all, root);
	for (int i = 0; i < int(all.size()-1); i++)
	{
		bool found = true;
		for (int j = 0; j < int(all.size() - i - 1); j++)
		{
			if (atoi(all[j].get_priority().c_str())>atoi(all[j + 1].get_priority().c_str()))
			{
				swap(all[j], all[j + 1]);
					found = false;
			}
		}

		if (found)   break;
	}

	for (Task i : all)
	{
		cout << i;
	}
}


void BST:: remove(Node* &r,Task t)
{

	if (r == NULL)
		return;


	if (t.get_name() < r->data.get_name())
	{
		remove(r->left, t);
	}
	else if (t.get_name() > r->data.get_name())
	{
		remove(r->right, t);

	}
	
	else if(r->data==t){

		if (r->left != NULL&&r->right != NULL)
		{
			
			r->data = findmin(r->right);
			
			remove(r->right,r->data);

		}
		else
		{
			Node *del = r;
			r = (r->left != NULL) ? r->left : r->right;

			delete del;

		}
	}
	else
	{
		remove(r->left, t);
	}
	
}


Task BST:: findmin(Node* r)
{
	Task t;
	while (r->left)
	{
		r = r->left;
	}
	t = r->data;
	return t;
}


void BST::remove_by_name(Node* &n, string &val)
{
	if (n == NULL)
		return;
	(n->data.get_name() > val) ? remove_by_name(n->left, val) : remove_by_name(n->right, val);

	if (n->left != NULL&&n->right != NULL)
	{
		n->data = findmin(n->right);
		remove_by_name(n->right, n->data.get_name());
	}
	else
	{
		Node* del = n;
		n = (n->left != NULL) ? n->left : n->right;
	}

}


void BST::remove_by_name(string &val)
{
	remove_by_name(root,val);
}
