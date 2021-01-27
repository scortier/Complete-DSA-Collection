/*
A and B are playing a game. At the beginning there are n coins. Given two more numbers
x and y. In each move a player can pick x or y or l coins. A always starts the game.
The player who picks the last coin wins the game. For a given value of n, find whether
 A will win the game or not if both are playing optimally.
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
We can observe that A wins game for n coins only when it loses for coins n-1, n-x and n-y.
*/
#include<bits/stdc++.h>
using namespace std;

// int cnt=0;
// void game(int n,int x,int y)
// {
// 	while(n)
// 	{
// 		if(n>x) {n-=x;cnt++;}

// 	}
// }
void game_dp(int n, int x, int y) {
	int t[n + 1];

	t[0] = false;
	t[1] = true;

	for (int i = 2; i <= n; i++)
	{
		if (i - 1 >= 0 and !t[i - 1])
			t[i] = true;
		else if (i - x >= 0 and !t[i - x])
			t[i] = true;
		else if (i - y >= 0 and !t[i - y])
			t[i] = true;

		else
			t[i] = false;
	}

	return t[n];
}



int32_t main()
{
	int x = 3, y = 4, n = 5;
	if (game(n, x, y))
		cout << 'A';
	else
		cout << 'B';
	return 0;
}