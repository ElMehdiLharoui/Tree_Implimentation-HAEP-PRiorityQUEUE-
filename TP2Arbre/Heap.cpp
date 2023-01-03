#include "Heap.h"
#include <algorithm>
Heap::Heap()
{	
	nbelement = 0;
}

int parent(int index)
{
	return (index - 1) / 2;
}
int leftchild(int index)
{
	return (2 * index + 1) ;
}
int rightchild(int index)
{
	return (2 * index + 2);
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Heap::InsertTree(int element)
{
	vect.push_back(element);
	nbelement++;


	int e = nbelement - 1;
	while (e != 0 && vect[parent(e)] < vect[e])
	{
		swap(&vect[parent(e)], &vect[e]);
		e = parent(e);
	}

}

void Heap::display()
{
	int heith = floor(log(nbelement) / log(2)) + 1;
	int i=0;
	int j = 0;
	for (i = 0; i < heith; i++)
	{
		int power=pow(2,i);
		while (power > 0)
		{
			if (j<nbelement) {

				cout << vect[j] << " ";
				j++;
				power--;
			}
			else break;
		}
		cout << endl;
		
	}
}

void Heap::maxHaep(int i)
{
	int left = leftchild(i);
	int right = rightchild(i);

	int larg = i;

	if (i <= nbelement && vect[left] > vect[larg])
	{
		larg = left;
	}
	if (i <= nbelement && vect[right] > vect[larg])
	{
		larg = right;
	}
	if(i!=larg)
	{
		int temp = vect[i];
		vect[i] = vect[larg];
		vect[larg] = temp;
		maxHaep(larg);
	}


}
