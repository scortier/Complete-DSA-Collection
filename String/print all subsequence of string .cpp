#include<bits/stdc++.h>
using namespace std;

void subsequence(string s, string osf)
{
	int n = s.size();
	if (n == 0)
	{
		cout << osf << endl;
		return;
	}
	char ch = s[0];
	string r = s.substr(1); //rest of the string from 1 to n-1
	subsequence(r, osf + ch);
	subsequence(r, osf);
}

int main()
{
	string s;
	cin >> s;
	subsequence(s, "");
	return 0;
}