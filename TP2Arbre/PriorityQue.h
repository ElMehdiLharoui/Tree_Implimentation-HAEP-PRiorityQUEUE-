#pragma once
#include <iostream>
#include <set>
using namespace std;
struct Node{
	int data;
	int Priority;
};
class PriorityQue
{
private:
	set<pair<int,int>>list;
public:
	PriorityQue();
	void InsertElement(int d, int p);
	void supprimer();
	void Afficher();
};

