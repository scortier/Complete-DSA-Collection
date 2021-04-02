/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

int lpsubstr_cou(string s)
{
	bool dp[s.size()][s.size()];
	int count = 0;
//1 gap=2 length of string
	for (int gap = 0; gap < s.size(); gap++)
	{	//each diagonal start with 0th row
		//gap 4 diagona start from 0th row and 4th col col=0+4
		//nth diag 0th row and  nth col se start hota h and khtm last col m hota h
		int row = 0;
		for (int col = 0 + gap; col < dp.length; col++)
		{
			row++;
			if (gap == 0)
				dp[row][col] = true;
			else if (gap == 1)
			{	if (s[row] == s[col]) {dp[row][col] = true;}
				else dp[row][col] = false;
			}
			else //gap>=2 means atleast 3char so inner word bhi aagye isme which is dp[i+1][j-1] left down / esa
			{
				if (s[row] == s[col] and dp[row + 1][col - 1])
				{
					dp[row][col] = true;
				}
				else
					dp[row][col] = false;
			}

			if (dp[row][col]) count++;
		}
	}
	return count;
}

int32_t main()
{

	return 0;
}