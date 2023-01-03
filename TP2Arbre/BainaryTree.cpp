#include "BainaryTree.h"
#include<queue>
BainaryTree::BainaryTree(int d)
{
	data = d;
	FD = NULL;
	FG = NULL;
}

BainaryTree* creerNode(int d)
{
    BainaryTree* nv = new BainaryTree(d);
    return nv;
}




 BainaryTree* BainaryTree::insertElement(int d,BainaryTree* root)
{
     if (root == NULL)
     {
         root = creerNode(d);
         return root;
     }
    queue<BainaryTree*>que;
    que.push(root);
    while (!que.empty())
    {
        BainaryTree* element = que.front();
        que.pop();
        if (element->FG != NULL)
        {
            que.push(element->FG);

        }
        else
        {
            element->FG = creerNode(d);
            return root;
        }
        if (element->FD != NULL)
        {
            que.push(element->FD);
        }
        else
        {
            element->FD = creerNode(d);
            return root;

        }
    }
   // return root;
}

 

void BainaryTree::afficher(BainaryTree *ar)
{
    if (ar == NULL)
        return;
    queue<pair<BainaryTree*, int> >que;
    que.push({ ar, 1 });
    pair<BainaryTree*, int> par;
    while (!que.empty()) {
        par = que.front();
        que.pop();
        cout << "Level of " << par.first->data << " is " << par.second << " " << "\n";
        if (par.first->FG)
            que.push({ par.first->FG, par.second + 1 });
        if (par.first->FD)
            que.push({ par.first->FD, par.second + 1 });
    }
}

bool BainaryTree::find(BainaryTree* a, int data)
{
    if (a == NULL || a->data == data)
        return true;
    if (a->data <= data)
    {
        BainaryTree::find(a->FD, data);
    }
    else {

        BainaryTree::find(a->FG, data);
    }

    return false;
}
