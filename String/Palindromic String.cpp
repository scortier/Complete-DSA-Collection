//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

void palin(string s)
{
	int n = s.size(); int flag = 0;
	int i = 0, j = n - 1;
	while (i <= j)
		if (s[i] == s[j]) {
			i++; j--;
		}
		else {
			flag = 1;
		}
	if (flag == 1) cout << "Na hopaega tumse" << endl;
	else cout << "Ho gya" << endl;
}

int main() {
	string s = "acbca";
	palin(s);
	return 0;
}