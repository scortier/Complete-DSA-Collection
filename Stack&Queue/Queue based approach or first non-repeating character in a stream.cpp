/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
Create a count array of size 26(assuming only lower case characters are present) and initialize it with zero.
Create a queue of char datatype.
Store each character in queue and increase its frequency in the hash array.
For every character of stream, we check front of the queue.
If the frequency of character at the front of queue is one, then that will be the first non repeating character.
Else if frequency is more than 1, then we pop that element.
If queue became empty that means there are no non repeating character so we will print -1.
*/
#include<bits/stdc++.h>
using namespace std;

//solved using queue
void non_rep(string s)
{
	int cnt_Arr[26] = {0};

	int n = s.size();
	queue<char>q;
	for (int i = 0; i < n; i++)
	{
		q.push(s[i]);
		cnt_Arr[s[i] - 'a']++;

		//check for non repeating char
		while (!q.empty())
		{
			if (cnt_Arr[q.front() - 'a'] > 1)
				q.pop();
			else
				cout << q.front() << " ";
			break;
		}
		if (q.empty())
			cout << -1 << " ";
	}
	cout << endl;
}

string FirstNonRepeating(string A) {
	int n = A.size();
	vector<int>f(26, 0);
	vector<int>last(26, -1);
	for (int i = 0; i < A.size(); i++) {
		if (last[A[i] - 'a'] == -1)
			last[A[i] - 'a'] = i;
	}
	string ans = "";
	for (int i = 0; i < A.size(); i++) {
		f[A[i] - 'a']++;
		char ch = '#';
		int x = A.size() + 1;
		for (int j = 0; j < 26; j++) {
			if (f[j] == 1 and x > last[j]) {
				ch = char(j + 'a');
				x = last[j];
			}
		}
		ans += ch;
	}
	return ans;
}
//solved using DLL


int32_t main()
{

	return 0;
}