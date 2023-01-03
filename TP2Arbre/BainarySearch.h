#pragma once
#include <iostream>
#include<queue>
using namespace std;

template <class type>

class BainarySearch
{
private:
	type data;
	BainarySearch* FG;
	BainarySearch* FD;
public :
	BainarySearch(type d);
	static BainarySearch* InsertElement(BainarySearch* root, type d);
	static BainarySearch* creerNode(type d);
	bool operator>=(type d);
	bool operator<(type d);
	static void afficher(BainarySearch* root);
	static bool find(BainarySearch* root, type data);
};

template<class type>
inline BainarySearch<type>::BainarySearch(type d)
{
	data = d;
	FG = NULL;
	FD = NULL;

}
template<class type>
inline BainarySearch<type>* BainarySearch<type>::creerNode(type d)
{
	BainarySearch* nv = new BainarySearch(d);
	return nv;
}



template<class type>
inline BainarySearch<type>* BainarySearch<type>::InsertElement(BainarySearch<type>* root, type d)
{
	if (root == NULL)
	{
		root = BainarySearch<type>::creerNode(d);
		return root;
	}

	if (root->data >= d)
	{
		root->FD = InsertElement(root->FD, d);
	}

	else
	{
		root->FG = InsertElement(root->FG, d);

	}
	return root;
}

template<class type>
inline bool BainarySearch<type>::operator>=(type d1)
{
	return this->data >= d1 ? true : false;
}

template<class type>
inline bool BainarySearch<type>::operator<(type d)
{
	return this->data < d ? true :false;
}
template<class type>
inline void BainarySearch<type>::afficher(BainarySearch<type>* ar)
{
	if (ar == NULL)
		return;
	// queue pour indique l'element et son ordre dans l'arbre
	queue<pair<BainarySearch*, int> >que;
	//intialise le root a 1 
	que.push({ ar, 1 });
	// pair pour parcourir le QUEue
	pair<BainarySearch*, int> par;
	// tansue il ya des elements dans la Queue
	while (!que.empty()) {
		// Pair recupure  le root et l'ordre
		par = que.front();

		// supprimer l'element du Queue
		que.pop();
		// afficher le Pair
		cout << "Level of " << par.first->data << " is " << par.second << " " << "\n";
		//Ajouter les fils au queue
		if (par.first->FG)
			que.push({ par.first->FG, par.second + 1 });
		if (par.first->FD)
			que.push({ par.first->FD, par.second + 1 });
	}
}
template<class type>
inline bool BainarySearch<type>::find(BainarySearch* a, type d)
{
	if (a == NULL || a->data == d)
		return true;
	if (a->data <= d)
	{
		BainarySearch<type>::find(a->FD, d);
	}
	else {

		BainarySearch<type>::find(a->FG, d);
	}

	return false;
}