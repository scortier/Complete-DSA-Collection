/*
arr[] = {1,3,5,2,7}
O/P :  {3,5,7,7,-1}
*/


#include<bits/stdc++.h>
using namespace std;
/*
void NGR_brute(int a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (a[j] > a[i]) { a[i] = a[j]; break;}
			else a[i] = -1;
		}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
*/
/*
Stack empty -> -1
s.top()> arr[i] return s.top()
s.top()<=arr[i]
	1.stack empty
	2.st.top() > arr[i]
*/
void NGR_stack(int arr[], int arr_size)
{
	vector<int>v;// to store the element
	stack<int>st;
	for (int i = arr_size - 1; i >= 0; i--) //moving from right to left in array
	{
		if (st.size() == 0) v.push_back(-1);	//last ele of array has no ele to its right so -1

		else if (st.size() > 0 and st.top() > arr[i])
			v.push_back(st.top());

		else if (st.size() > 0 and st.top() <= arr[i])
		{
			while (st.size() > 0 and st.top() <= arr[i])
				st.pop();	//pop till arr[i] is greater than top

			if (st.size() == 0)	//if continues pop make size of stack =0 then push -1;
				v.push_back(-1);
			else
				v.push_back(st.top());
		}
		st.push(arr[i]);

	}
	reverse(v.begin(), v.end());	// as the iteration happened from last element of array.
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << " ";

}
int32_t main()
{
	int n = 4;
	// cin >> n;
	int a[n] = {1, 3, 2, 4};
	//for (int i = 0; i < n; i++) cin >> a[i];
	NGR_stack(a, n);
	return 0;
}