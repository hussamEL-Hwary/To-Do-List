#include<bits\stdc++.h>
#include"AVL.h"
#include"Task.h"
using namespace std;



AVL::AVL()
{
	root = NULL;
}


int AVL:: get_hight(Node* &n)
{
	
	return n == NULL ? -1 : n->hight;

}


void AVL::insert(Node* &n, Task &val)
{

	if (n == NULL)
	{
		n = new Node(val, NULL, NULL);
		return;
	}

	if (val.get_name() > n->data.get_name())
		insert(n->right, val);
	else
		insert(n->left, val);

	balance(n);
}


void AVL:: balance(Node* &n)
{
	if (get_hight(n->left) - get_hight(n->right) > 1)
	{
		if (get_hight(n->left->left) >= get_hight(n->left->right))
			LL(n);
		else

			LR(n);
	}
	else if (get_hight(n->right)-get_hight(n->left)>1)
	{
		if (get_hight(n->right->right) >= get_hight(n->right->left))
			RR(n);
		else
			RL(n);
	}
	n->hight = max(get_hight(n->left), get_hight(n->right)) + 1;

}


void AVL::LL(Node* &n)
{
	Node* n1 = n->left;
	n->left = n1->right;
	n1->right = n;
	n1->hight = max(get_hight(n1->left), get_hight(n1->right)) + 1;
	n->hight = max(get_hight(n->left), get_hight(n->right)) + 1;
	n = n1;
}


void AVL::RR(Node* &n)
{
	Node* n1 = n->right;
	n->right = n1->left;
	n1->left = n;
	n1->hight = max(get_hight(n1->left), get_hight(n1->right)) + 1;
	n->hight = max(get_hight(n->left), get_hight(n->right)) + 1;
	n = n1;

}


void AVL::LR(Node* &n)
{
	RR(n->left);
	LL(n);
}


void AVL::RL(Node* &n)
{
	LL(n->right);
	RR(n);
}


void AVL:: insert(Task &val)
{
	insert(root, val);
}


void AVL::load()
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


void AVL::save()
{

	fstream out("mytasks.txt", ios::out | ios::trunc);
	save(out, root);
	out.close();

}


void AVL::save(fstream &out, Node* &n)
{
	if (n == NULL)
		return;
	out << n->data.get_name() << "|" << n->data.get_description() << "|"
		<< n->data.get_priority() << "|" << n->data.get_DueDate() << "|"
		<< n->data.get_numberOfDays() << "|" << '\n';

	save(out, n->left);
	save(out, n->right);
}


void AVL::findall(vector<Task>& all, Node* &n)
{
	if (n == NULL)   return;
	else
		all.push_back(n->data);

	findall(all, n->left);
	findall(all, n->right);
}


void AVL::listOrderd()
{
	vector<Task>all;
	findall(all, root);
	for (int i = 0; i < int(all.size() - 1); i++)
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


void AVL::search(string name)
{
	//lastsercoun = 0;
	search(root, name);
}


void AVL::search(Node* &n, string &val)
{
	if (n == NULL)
	{
		cout << "Task not found\n";

	}
	else if (val < n->data.get_name())
	{
		//lastsercoun++;
		search(n->left, val);
	}
	else if (val>n->data.get_name())
	{
		//lastsercoun++;
		search(n->right, val);
	}
	else
	{
		cout << n->data;
	}

}


Task AVL::removeTopPriority()
{

	Task pr;
	pr.set_priority("-1");

	traverse(root, pr);

	remove(root, pr);

	return pr;

}


void AVL::traverse(Node* &r, Task &pr)
{
	if (r == NULL)
		return;
	int x = atoi(r->data.get_priority().c_str());
	if (x > atoi(pr.get_priority().c_str()))
	{
		pr = r->data;

	}

	traverse(r->left, pr);
	traverse(r->right, pr);

}


void AVL::remove(Node* &r, Task t)
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

	else if (r->data == t){

		if (r->left != NULL&&r->right != NULL)
		{

			r->data = findmin(r->right);

			remove(r->right, r->data);

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


Task AVL::findmin(Node* r)
{
	Task t;
	while (r->left)
	{
		r = r->left;
	}
	t = r->data;
	return t;
}


void AVL::remove_by_name(Node* &n, string &val)
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


void AVL::remove_by_name(string &val)
{
	remove_by_name(root, val);
}

