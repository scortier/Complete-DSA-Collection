// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;

/**********====================########################=================***********/
#define N 4

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j];
		cout << endl;
	}
}

bool canSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQUtil(int board[N][N], int col)
{
	/* base case: If all queens are placed
	  then return true */
	if (col >= N)
		return true;

	/* Consider this column and try placing
	   this queen in all rows one by one */
	for (int i = 0; i < N; i++) {
		/* Check if the queen can be placed on
		  board[i][col] */
		if (canSafe(board, i, col)) {
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			if (solveNQUtil(board, col + 1))
				return true;

			/* If placing queen in board[i][col]
			   doesn't lead to a solution, then
			   remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If the queen cannot be placed in any row in
	    this colum col  then return false */
	return false;
}

bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};

	if (solveNQUtil(board, 0) == false) {
		printf("Solution does not exist");
		return false;
	}

	printSolution(board);
	return true;
}
int32_t main()
{
	solveNQ();

	return 0;
}





/////////////////////////////////////////////////////


class Solution {
public:
	vector<vector<string>>ans;

	//func to check if queen can be placed or not in part row
	bool isSafe(int row, int col, int n, vector<string>&board)
	{
		for (int i = 0; i < row; i++) //check the column
		{
			if (board[i][col] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) //check left diagonal
		{
			if (board[i][j] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; i--, j++) //check right diagonal
		{
			if (board[i][j] == 'Q')
				return false;
		}
		// If there is no queen placed in left, or right diagonal or in the same column, then place the queen by returning true
		return true;
	}

	//to generate all possible combination
	void util(vector<string>&board, int n, int row)
	{
// if we have reached the end for a particular column, push the current combination into the result and return
		if (row == n)
		{
			ans.push_back(board);
			return;
		}
//  We iterate over column and hence row ,left and right diagonal  remain to be considered which we consider in check function
		for (int col = 0; col < n; col++)
		{
			//if it can be placed
			if (isSafe(row, col, n, board))
			{
				board[row][col] = 'Q'; //place the queen in that row and col
				util(board, n, row + 1); //check the next row for plaement
				board[row][col] = '.'; //reset it for future column and row combination.
			}
		}
		return;
	}

	vector<vector<string>> solveNQueens(int n) {
		vector<string>board(n, string(n, '.'));
		util(board, n, 0);
		return ans;
	}
};