#include<bits\stdc++.h>
#include"Task.h"
using namespace std;

#pragma once
class BST 
{
private:
	class Node
	{
	public:
		Task data;
		Node* left;
		Node* right;
	};

	Node* root;

	int lastincount;
	int lastdelcount;
	int lastsercoun;

	void insert(Node * &n, Task &t);

	void search(Node* &n, string &val);

	void save(fstream &out, Node* &n);

	void traverse(Node* &r, Task &pr);

	void findall(vector<Task>&all, Node* &n);

	void remove(Node* &r,Task t);

	Task findmin(Node* r);

	void remove_by_name(Node* &n ,string &val);
public:

	BST();

	void insert(Task &in);     /**OK**/

	void search(string name);  /**OK**/

	Task removeTopPriority();  /**OK**/

	void save();              /**OK**/

	void load();              /**OK**/
	
	void listOrderd();        /**OK**/

	void remove_by_name(string &val);
};