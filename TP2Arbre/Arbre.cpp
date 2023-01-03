#include "Arbre.h"
#include<queue>

Arbre::Arbre(int indix)
{
   // Priority = P;
    data = indix;
    left = NULL;
    right = NULL;
}

Arbre::Arbre()
{
    data = 0;
    //Priority = 0;
    left = NULL;
    right = NULL;
}

Arbre* Arbre::createNode(int key)
{
    Arbre* arr;
    data = key;
   // Priority = rand() % 100;
    left = right = NULL;
    arr = new Arbre();
    return nullptr;
}

Arbre::Arbre(int i, Arbre* l, Arbre* r)
{
    //Priority = P;
    data = i;
    left = l;
    right = r;
}

 Arbre* Arbre::ArrayToBST(set<int>& array, int left, int right)
{
    if (left > right)
    {
    return nullptr;
    }
    
    int mediam = (left + right) / 2;

    std::set<int>::iterator it = array.begin();
    
    
    Arbre* root = new Arbre(*it);
    
    array.erase(it);
    
    root->left = ArrayToBST(array, left, mediam - 1);
    
    root->right = ArrayToBST(array, mediam + 1, right);
    
    return root;
}
 bool Arbre::find(Arbre* a, int d)
 {
     if (a == NULL || a->data == d)
         return true;
     if (a->data <= d)
     {
          Arbre::find(a->right,d);
     }
     else {

      Arbre::find(a->left, d);
     }
     
     return false;
}
 /*
 sort => pas de priorite
 !sort => probleme de root pas equilibre 
 */
Arbre* Arbre::RemoveElement(int Value)
{
    return nullptr;
}

 void Arbre::Display(Arbre *ar)
{
     if (ar == NULL)
         return;
     queue<pair<Arbre*, int> >que;
     que.push({ ar, 1 });
     pair<Arbre*, int> par;
     while (!que.empty()) {
         par = que.front();
         que.pop();
         cout << "Level of " << par.first->data << " is " << par.second << " " << "\n";
         if (par.first->left)
             que.push({ par.first->left, par.second + 1 });
         if (par.first->right)
             que.push({ par.first->right, par.second + 1 });
     }
}
