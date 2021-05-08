/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;
int R, C;


void print(char mat[][50]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//W N E S
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void floodfill(char mat[][50], int i, int j, char ch, char color)
{
	//Base Case
	if (i<0 or j<0 or i >= R or j >= C)
		return;

	//Figure Boundary Condition
	if (mat[i][j] != ch)
		return;

	//Recursive Call
	mat[i][j] = color;
	for (int k = 0; k < 4; k++)
	{
		floodfill(mat, i + dx[k], j + dy[k], ch, color);
	}
}

int32_t main()
{
	char mat[50][50];
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mat[i][j];
		}
	}

	print(mat);
	floodfill(mat, 8, 13, '.', 'R');
	floodfill(mat, 0, 0, '.', '!');
	print(mat);
	return 0;
}