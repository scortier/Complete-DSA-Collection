//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

string revstr(string s)
{
	int n = s.size();
	for (int i = 0; i < n / 2; i++)
	{
		swap(s[i], s[n - i - 1]);
	}
	return s;
}

int main() {
	string str = "geeksforgeeks";
	cout << revstr(str);
	return 0;
}