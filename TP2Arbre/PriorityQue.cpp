#include "PriorityQue.h"
#include <algorithm>
PriorityQue::PriorityQue()
{
}
void PriorityQue::InsertElement(int data, int priority)
{
	list.insert({data, priority});
}

void PriorityQue::supprimer()
{
	list.erase(list.begin());	
}

void PriorityQue::Afficher()
{
	set<pair<int, int>>::iterator i;
	for (i = list.begin(); i != list.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}
}
