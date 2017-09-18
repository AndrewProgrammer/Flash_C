#include <iostream>

#include "Tree.h"
#include "Treenode.h"
using namespace std;

int main()
{
	setlocale(0, "ru");
	Tree<int> tree;
	tree.Add(50);
	tree.Add(25);
	tree.Add(12);
	tree.Add(6);
	tree.Add(18);
	tree.Add(75);
	tree.Add(90);
	tree.Add(99);
	tree.Add(100);
	tree.Add(80);

	cout << tree << endl;
	cout << "Max = " << tree.Maximum(tree.GetRoot())->GetValue() << endl;
	cout << "Min = " << tree.Minimum(tree.GetRoot())->GetValue() << endl;
	cout << "¬водить правильные значени€: " << endl;
	cout << "Search = " << tree.Search(12)->GetValue() << endl;
	cout << "Previous = " << tree.Previous(tree.Search(50))->GetValue() << endl;
	cout << "Next = " << tree.Next(tree.Search(50))->GetValue() << endl;
	cout << "Remove = " << tree.Remove(50) << endl;
	Tree<int> tree1(tree);
	return 0;
}