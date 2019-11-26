#include<iostream>]

using namespace std;

struct node {
	int value;
	node* left, * right;
	node();
};


void print_Tree(node*, int);

struct Tree {
	Tree(int*, int);
	void add(int);
	void show();
	node* DeleteNode(node*, int);
	node* root;
	void push(node*, node*);



};

int main() {

	int b;
	cout << "enter size of the array" << endl;
	int n;
	cin >> n;
	cout << "enter the array" << endl;
	int* mas = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
	}
	Tree binTree(mas, n);
	binTree.show();
	cout << "enter the number to delete" << endl;
	cin >> b;
	binTree.DeleteNode(binTree.root,b);
	binTree.show();
	
}

Tree::Tree(int* arr, int size)
{
	root = NULL;
	for (int i = 0; i < size; i++) {
		add(arr[i]);
	}
}

node::node()
{
	left = NULL;
	right = NULL;
}

void Tree::add(int val)
{
	node* cur = new node;
	cur->value = val;
	if (!root)root = cur;
	else push(root, cur);
}
void Tree::push(node* cur, node* next)
{
	if (next->value >= cur->value)
	{
		if (cur->right)push(cur->right, next);
		else cur->right = next;
	}
	else
	{
		if (cur->left)push(cur->left, next);
		else cur->left = next;
	}
}

node* Tree:: DeleteNode(node* p, int val) {
	if (p == NULL)
		return p;

	if (val == p->value) {

		node* tmp;
		if (p->right == NULL)
			tmp = p->left;
		else {

			node* ptr = p->right;
			if (ptr->left == NULL) {
				ptr->left = p->left;
				tmp = ptr;
			}
			else {

				node* pmin = ptr->left;
				while (pmin->left != NULL) {
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = p->left;
				pmin->right = p->right;
				tmp = pmin;
			}
		}

		delete p;
		return tmp;
	}
	else if (val < p->value)
		p->left = DeleteNode(p->left, val);
	else
		p->right = DeleteNode(p->right, val);
	return p;
}



void Tree::show()
{
	print_Tree(root, 0);
}

void print_Tree(node* p, int level)
{
	if (p)
	{
		print_Tree(p->right, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->value << endl;
		print_Tree(p->left, level + 1);
	}
}





