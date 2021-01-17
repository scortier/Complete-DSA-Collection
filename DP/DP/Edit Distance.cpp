/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

//Recursion
// int edit(string x, string y, int m, int n)
// {
// 	//base condn
// 	if (m == 0) return n;
// 	if (n == 0) return m;


// 	if (x[m - 1] == y[n - 1])//when the last letter of the both are same.
// 		return edit(x, y, m - 1, n - 1);
// 	else
// 		return
// 		    (1 + min(edit(x, y, m - 1, n), //remove
// 		             edit(x, y, m, n - 1), //insert
// 		             edit(x, y, m - 1, n - 1) //replace
// 		            ));
// }



//MEMOIZE
int t[101][101];
int edit_memoize(string x, string y, int m, int n)
{
	//base condn by initialization
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (m == 0) {t[i][j] = n;}
			if (n == 0) {t[i][j] = m;}
		}
	}


	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
// If last characters of two strings are same, nothing
// much to do. Ignore last characters and get count for
// remaining strings.
			if (x[i - 1] == y[j - 1]) {
				t[i][j] =  t[i - 1][j - 1];
			}
			else {
// If last characters are not same, consider all three
				// operations on last character of first string,
				// recursively compute minimum cost for all three
				// operations and take minimum of three values.
				//
				t[i][j] = 1 + min(t[i - 1][j - 1], min(t[i][j - 1], t[i - 1][j]));
			}
		}
	}
	return t[m][n];
}

int32_t main()
{
	string str1 = "sunday";
	string str2 = "saturday";

	cout << edit_memoize(str1, str2, str1.length(),
	                     str2.length());

	return 0;
}