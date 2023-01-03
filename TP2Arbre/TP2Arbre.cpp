// TP2Arbre.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include "Arbre.h"
#include "Heap.h"
#include "BainaryTree.h"
#include <time.h>
#include "BainarySearch.h"
#include "PriorityQue.h"
using namespace std;
int main()
{
	//Arbre binaire de rechrche equilibre 
	// en utilisent STL set pour stocker les donnees d'une ordoner puis diviser le en deux 
	// c a d les donnees en gauche sont inferieurs au milieux (root) 
	// les doonees en droit sont superieure au mlieux (root)
	set<int> element;
	srand(time(NULL));
	// inserer les elements
	for (int i = 0; i <= 700000 - 1; i++)
	{
		element.insert( rand() % 700000);
	}
	Arbre* d = new Arbre();
	
	// donner l'indice debut et de fin et le set 
	
	d = Arbre::ArrayToBST(element,0,element.size()-1);
	
	// Afficher l'arbre ainsi l'ordre des elements
	  
	// Arbre::Display(d);
	
	// fonction de recherche
	
	//cout <<	"existe " << Arbre::find(d, 0) <<" element"<<endl;

	// temp d'excution en 10 second


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*bainary tree*/
	// Arbre binare simple qui cherche le fils diferenet au NULL et insere
	BainaryTree* root1 = new BainaryTree(5);
	//insertion des donnees
	for (int i = 0; i <= 100000 - 1; i++)
	{
		BainaryTree::insertElement(rand() % 700000, root1);
	}
	// BainaryTree::afficher(root1);
	// cout << "existe " << BainaryTree::find(root1, 0) << " element" << endl;
	
	/// ///////////////////////////////////////////////////////////////////////////////////
	// Arbre Binaire de rechrche NON equilibre 
	
	BainarySearch<int>* root2 = new BainarySearch<int>(1);
	for (int i = 0; i <= 700000 - 1; i++)
	{
		BainarySearch<int>::InsertElement( root2, rand() % 700000);
	}
	//BainarySearch<char>::afficher(root2);
	cout << "existe " << BainarySearch<int>::find(root2, 65) << " element" << endl;


	
//////////////////////////////////////////////////////////////////////////////////////////	 
	
	//Priority QUEUE en utilisent SET

	PriorityQue* p1 = new PriorityQue();
	p1->InsertElement(123, 1);
	p1->InsertElement(96, 3);
	p1->InsertElement(12, 4);
	p1->InsertElement(98, 2);

	p1->supprimer();
	//	p1->Afficher();

////////////////////////////////////////////////////////////////////////////////

	// implimentation de HEAP
	Heap* h = new Heap();

	h->InsertTree(78);
	h->InsertTree(66);
	h->InsertTree(35);
	h->InsertTree(29);
	h->InsertTree(33);
	h->InsertTree(21);
	h->InsertTree(9);
	h->InsertTree(12);
	h->InsertTree(5);
	h->InsertTree(10);
//	h->display();



}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
