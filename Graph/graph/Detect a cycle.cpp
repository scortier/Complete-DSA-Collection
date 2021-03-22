#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector < int > v = {1, 3, 2, 5};
	cout << v.capacity() << endl; // this prints 4.
	v.push_back(12);
	cout << v.capacity() << endl; // predict this
	return 0;
}