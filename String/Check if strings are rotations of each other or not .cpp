//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;
//TC:O(N) SC:O(N)
//KMP ALGORITHM
bool isRotation(string a, string b)
{
	int n = a.size();
	int m = b.size();
	if (n != m)
		return false;

	int lps[n];
	int len = 0;
	int i = 1;

	lps[0] = 0;

	while (i < n)
	{
		if (a[i] == b[len])
		{
			lps[i] = ++len;
			++i;
		}
		else
		{
			if (len == 0)
			{
				lps[i] = 0;
				++i;
			}
			else
			{
				len = lps[len - 1];
			}
		}
	}
	i = 0;

	for (int k = lps[n - 1]; k < m; ++k)
	{
		if (b[k] != a[i++])
			return false;
	}
	return true;
}


int main() {
	string s1 = "ABACD";
	string s2 = "CDABA";
	cout << (isRotation(s1, s2) ?
	         "1" : "0");
}