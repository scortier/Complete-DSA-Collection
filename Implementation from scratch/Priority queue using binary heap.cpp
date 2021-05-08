#include<bits/stdc++.h>
using namesoace std;

int height[50];
int size = -1;

//Indexing start from 0
// return the index of parent node of given node
int parent(int i)
{
	return (i - 1) / 2;
}

//return thr index of the left child of the given node
int leftchild(int i)
{
	return ((2 * i) + 1);
}

int rightchild(int i)
{
	return ((2 * i) + 2);
}

//func to shift up the node in order to maintain the heap property
void shiftup(int i)
{
	while (i > 0 and height[parent(i)] < height[i])
	{
		//swap parent and curr node
		swap(height[parent(i)], height[i]);

		//update i to pareent i
		i = parent(i);
	}
}

//func to shift down the node in order to maintain the heap property
void shiftdown(int i)
{
	int maxIndex = i;

	//left child
	int l = leftchild(i);

	if (l <= size and height[l] > height[maxIndex])
		maxIndex = l;

	int r = rightchild(i);

	if (r <= size and height[r] > height[maxIndex])
		maxIndex = r;

	//if i not same as max index
	if (i! -maxIndex)
	{
		swap(height[i], height[maxIndex]);
		shiftdown(maxIndex);
	}
}

//fuction to indert a new ele in binary heap
void insert(int p)
{
	size = size + 1;
	height[size] = p;

	//shift up to maintain heap property
	shiftup(size);
}

//function to extract the ele with maximum priority
int extractMax()
{
	int result = height[0];

	//replace the value at the root with the last leaf
	height[0] = height[size];
	size = size - 1;


}