#pragma once
#include <iostream>
using namespace std;
#include <set>


class Arbre
{
	int data;
	Arbre* left;
	Arbre* right;
public:
	Arbre(int indix);
	Arbre();
	Arbre* createNode(int key);
	Arbre(int i, Arbre* l, Arbre* r);
    static Arbre* ArrayToBST(set<int>&l,int left,int right);
	static bool find(Arbre* a, int d);
	Arbre* RemoveElement(int Value);
	static void Display(Arbre *ar);
};
