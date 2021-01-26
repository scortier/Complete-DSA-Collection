/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

//using sort
int solve(string s, int k)
{
	sort(s.begin(), s.end());
	int cnt_arr[26] = {0};
	for (int i = 0; i < s.size(); i++)
	{
		cnt_arr[s[i] - 'a']++;
		if (max < cnt_arr[i]) {
			max = cnt_arr[i];
			// result = (char)(i + 'a');
		}

	}

}

int32_t main()
{

	return 0;
}