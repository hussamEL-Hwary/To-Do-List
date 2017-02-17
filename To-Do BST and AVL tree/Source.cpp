#include<bits\stdc++.h>
#include"Task.h"
#include"BST.h"
#include"AVL.h"
using namespace std;

template<class T>
void start(T &mainobj)
{
	mainobj.load();

    loop:
	
	options();
	int inter;
	int op;
	cin >> inter;
	if (inter == 1)
	{
		cin.ignore();
		system("cls");
		Task tmp = tmp.make_task();
		mainobj.insert(tmp);
		system("cls");
		mainmenu();
		cin >> op;
		if (op == 1)
		{
			system("cls");
			goto loop;
		}
		else
		{
			mainobj.save();
			return;
		}

	}
	else if (inter == 2)
	{
		cout << "Enter Task name: ";
			string s;
		getline(cin, s);
		system("cls");
		mainobj.search(s);
		
		mainmenu();
		cin >> op;
		if (op == 1)
		{
			system("cls");
			goto loop;
		}
		else
		{
			mainobj.save();
			return;
	   	
		}
		
	}
	else if (inter == 3)
	{
		cout << "1-> remove top priority \n";
		cout << "2-> remove By name \n";
		int num;
		cin >> num;
		if (num == 1)
		{
			system("cls");
			Task t = mainobj.removeTopPriority();
			cout << t << endl;
		}
		else if (num == 2)
		{
			string tmpname;
			cout << "Enter Task name \n";
			getline(cin, tmpname);
			mainobj.remove_by_name(tmpname);
			cout << "Task succesfully removed \n";
			
		}

		mainmenu();
		cin >> op;
		if (op == 1)
		{
			system("cls");
			goto loop;
		}
		else

		{
			mainobj.save();
			return;
		}
	}
	else if (inter == 4)
	{
		mainobj.listOrderd();
	
		mainmenu();
		cin >> op;
		if (op == 1)
		{
			system("cls");
			goto loop;
		}
		else

		{
			mainobj.save();
			return;
		}
	}
	else if(inter == 5)
	{
		mainobj.save();
		return;
	}
	else
	{
		cout << "You entered wrong value \n";
			return;
	}
	
}

void options()
{
	cout << "1-> insert \n";
	cout << "2-> search \n";
	cout << "3-> Delete \n";
	cout << "4-> List Tasks Orderd By priority \n";
	cout << "5-> Exit programe \n";
}

void mainmenu()
{
	cout << "1-> go to main menu \n";
	cout << "2-> Exit programe \n";

}

int main()
{	
	BST b;
	AVL V;
	
	cout << "Which data structure \n";
	cout << "1-> Binary search Tree (BST) \n";
	cout << "2-> AVL Tree \n";
	int val;
	cin >> val;

	if (val == 1)
	{
		system("cls");
		start(b);
	}
	else if (val == 2)
	{
		system("cls");
		start(V);
	}

	else
		return 0;
	
	return 0;
}