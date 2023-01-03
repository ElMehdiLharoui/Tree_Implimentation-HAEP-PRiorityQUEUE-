#pragma once
#include <iostream>
using namespace std;
class BainaryTree
{
public:
	int data;
	BainaryTree* FG;
	BainaryTree* FD;
	BainaryTree(int d);
	static BainaryTree* insertElement(int d, BainaryTree* root);
	static void afficher(BainaryTree* ar);
	static bool find(BainaryTree* ar, int data);
};

