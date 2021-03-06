#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Node
{
	int key;
	Node *left, *right;
};

typedef Node *PNode;

Node *push(int a, Node *tree)
{
	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		tree = new Node;
		tree->key = a;
		tree->left = NULL;
		tree->right = NULL;
	}
	else     // иначе
		if (a < tree->key)   //Если элемент x меньше корневого, уходим влево
			tree->left = push(a, tree->left); //Рекурсивно добавляем элемент
		else  //иначе уходим вправо
			tree->right = push(a, tree->right); //Рекурсивно добавляем элемент
	return(tree);
}

PNode Search(PNode Tree, int what)
{
	if (!Tree) return NULL;
	if (what == Tree->key) return Tree;
	if (what < Tree->key)
		return Search(Tree->left, what);
	else return Search(Tree->right, what);
}

void PrintLKP(PNode Tree)
{
	if (!Tree) return;
	PrintLKP(Tree->left);
	printf("%d ", Tree->key);
	PrintLKP(Tree->right);

}

void DeleteNode(PNode Tree)
{
	if (Tree == NULL) return;
	DeleteNode(Tree->left);
	DeleteNode(Tree->right);
	delete Tree;
}

int main()
{
	PNode Tree = NULL;
	int data;

	for (int i = 0; i < 5; i++)
	{
		cin >> data;
		Tree = push(data, Tree);
	}
	PrintLKP(Tree);
	cout << endl;
	PNode a = Search(Tree, 2);
	DeleteNode(Tree);
	system("pause");
	return 0;
}