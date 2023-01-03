#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Heap
{
private:

	vector<int> vect;
	int nbelement = -1;
public:

	Heap();
	void InsertTree(int);
	void display();
	void maxHaep(int);
};

