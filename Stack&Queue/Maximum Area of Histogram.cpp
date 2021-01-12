/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
A building can be expand only when its height is >=building current.
index     =	{-1,0,1,2,3,4,5,6,7}( -1 and 7 are the Pseudo building with h=0)
arr[] 	  = {6,2,5,4,5,1,6}
NSR(index)= {1,5,3,5,5,7,7}
NSL(index)= {-1,-1,1,1,3,-1,5}

width of the building =NSR-NSL-1;
Width ={1,5,1,3,1,7,1}
Area(arr*width)={6,10,5,12,5,7,6}



Building 4 expand stop where NSL & NSR.
Index of reqd Building
INdex of NSR,NSL

Index of Reqd Building= Index of NSR -  Index of NSL -1;

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> NSL(int a[], int n)
{
	vector<int>left;
	stack<pair<int, int>>s;
	int PseudoIndex = -1;

	for (int i = 0; i < n; i++)
	{
		if (s.size() == 0)
			left.push_back(PseudoIndex);
		else if (s.size() > 0 and s.top().first < a[i])
		{
			left.push_back(s.top().second);
		}
		else if (s.size() > 0 and s.top().first >= a[i])
		{
			while (s.size() > 0 and s.top().first >= a[i])
			{
				s.pop();
			}
			if (s.size() == 0)
				left.push_back(PseudoIndex);
			else
				left.push_back(s.top().second);
		}
		s.push({a[i], i});
	}
	return left;
	// for (auto i = left.begin(); i != left.end(); ++i)
	// cout << *i << " ";


}
vector<int> NSR(int a[], int n)
{
	vector<int>right;
	stack<pair<int, int>>s;
	int PseudoIndex = 7;

	for (int i = n - 1; i >= 0; i--)
	{
		if (s.size() == 0)
			right.push_back(PseudoIndex);
		else if (s.size() > 0 and s.top().first < a[i])
		{
			right.push_back(s.top().second);
		}
		else if (s.size() > 0 and s.top().first >= a[i])
		{
			while (s.size() > 0 and s.top().first >= a[i])
			{
				s.pop();
			}
			if (s.size() == 0)
				right.push_back(PseudoIndex);
			else
				right.push_back(s.top().second);
		}
		s.push({a[i], i});
	}
	reverse(right.begin(), right.end());
	return right;
	// for (auto i = right.begin(); i != right.end(); ++i)
	// 	cout << *i << " ";


}

int max_area(int a[], int n)
{	vector<int>right;
	vector<int>left;
// for (auto i = right.begin(); i != right.end(); ++i)
// 		cout << *i << " ";
	left = NSL(a, n);
	right = NSR(a, n);
	int width[n];
	int area[n];

	for (int i = 0; i < n; i++)
		width[i] = right[i] - left[i] - 1;

	for (int i = 0; i < n; i++)
		area[i] = a[i] * width[i];

	sort(area, area + n);
	return area[n - 1];
}



int32_t main()
{
	int n = 7;
	int a[n] = {6, 2, 5, 4, 5, 1, 6};
	cout << max_area(a, n) << endl;
	return 0;
}