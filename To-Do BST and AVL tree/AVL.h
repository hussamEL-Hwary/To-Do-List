#include<bits\stdc++.h>
#include"Task.h"
using namespace std;


#pragma once
class AVL
{

private:
	
	class Node
	{
	public:
		Task data;
		Node *left;
		Node *right;
		int hight;
		Node(Task tmp, Node* n1, Node* n2, int h=0)
		{
			data = tmp;
			left = n1;
			right = n2;
			hight = h;
		}
	};

	Node *root;

	void insert(Node* &n, Task &val);  /**OK**/

	int get_hight(Node* &n);          /**OK**/

	void balance(Node* &n);
	
	void LL(Node* &n);       /**1**/
	 
	void LR(Node* &n);      /**2**/

	void RR(Node* &n);      /**3**/

	void RL(Node* &n);     /**4**/


	void search(Node* &n, string &val);

	void save(fstream &out, Node* &n);

	void traverse(Node* &r, Task &pr);

	void findall(vector<Task>&all, Node* &n);

	void remove(Node* &r, Task t);

	Task findmin(Node* r);

	void remove_by_name(Node* &n, string &val);

public:

	AVL();         
	
	Task get();
	
	void insert(Task &val);

	void save();              

	void load();          

	void listOrderd();        

	void search(string name);  

	Task removeTopPriority();

	void remove_by_name(string &val);
	
	
};