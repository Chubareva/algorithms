#include<iostream>]

using namespace std;

struct node {
	int value;
	node* left, * right;
	node();
};
void inorderPrint(node* root);
void postorderPrint(node* root);
int height(node*);
void print_Tree(node*, int);
void preorderPrint(node* root);
struct Tree {
	Tree(int*,int);
	void add(int);
	void show();
	node* search(node*, int);
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
	cout << "enter the number to search" << endl;
	cin >> b;
	cout<<binTree.search(binTree.root,b)<<endl;
	cout << height(binTree.root)<<" levels"<<endl;
	preorderPrint(binTree.root);
	cout << endl;
	inorderPrint(binTree.root);
	cout << endl;
	postorderPrint(binTree.root);
}

Tree::Tree(int *arr,int size)
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

node* Tree::search(node* cur, int val)
{
	if (!cur)return NULL;
	else if (val > cur->value)search(cur->right, val);
	else if (val < cur->value)search(cur->left, val);
	else return cur;
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
void preorderPrint(node* root)
{
	if (root == NULL)   
	{
		return;
	}
	cout << root->value << " ";
	preorderPrint(root->left); 

	preorderPrint(root->right);  
}
void inorderPrint(node* root)
{
	if (root == NULL)   
	{
		return;
	}
	preorderPrint(root->left);   
	cout << root->value << " ";
	preorderPrint(root->right);  
}

void postorderPrint(node* root)
{
	if (root == NULL)   
	{
		return;
	}
	preorderPrint(root->left);  
	preorderPrint(root->right);  
	cout << root->value << " ";
}

int height(node *p)
{
	int lefth = 0;
	if (p->left != NULL) {
		lefth =height(p->left); 
	}

	int righth = 0;
	if (p->right != NULL) {
		righth =height(p->right);
	}

	if (lefth > righth) {
		return lefth + 1; }
	else { return righth + 1; }
}