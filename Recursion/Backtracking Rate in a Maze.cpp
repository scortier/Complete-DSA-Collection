// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"

void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/
//A Maze is given as N*N binary matrix of blocks where source block is the upper
//left most block i.e., maze[0][0] and destination block is lower rightmost block
//i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination.
//The rat can move only in two directions: forward and down.

//In the maze matrix, 0 means the block is a dead end and
//1 means the block can be used in the path from source to destination.


/*Time Complexity: O(2^(n^2)).
The recursion can run upperbound 2^(n^2) times.

Space Complexity: O(n^2).
Output matrix is required so an extra space of size n*n is needed.*/


#define SIZE 4
bool canPlace(int maze[SIZE][SIZE], int x, int y)
{
	return
	    x >= 0 && x < SIZE &&
	    y >= 0 && y < SIZE &&
	    maze[x][y] == 1;
}

void printSolution(int solution[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			cout << solution[i][j] ;
		cout << endl;
	}
}

bool solveMaze(int maze[SIZE][SIZE], int x, int y, int solution[SIZE][SIZE])
{
	// if (x, y is goal) return true
	if (x == SIZE - 1 && y == SIZE - 1)
	{
		solution[x][y] = 1;
		return true;
	}

	// Check if maze[x][y] is valid
	if (canPlace(maze, x, y) == true)
	{
		// mark x, y as part of solution path
		solution[x][y] = 1;

		// Move forward in x or y direction
		if (solveMaze(maze, x + 1, y, solution) ||
		        solveMaze(maze, x, y + 1, solution))
			return true;

		//If none of the above movements work then BACKTRACK:
		//unmark x, y as part of solution path
		solution[x][y] = 0;
		return false;
	}

	return false;
}

//there may be more than one solutions,
//this function prints one of the feasible solutions
bool solveRatInMaze(int maze[SIZE][SIZE])
{
	int solution[SIZE][SIZE] = { {0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	if (!solveMaze(maze, 0, 0, solution))
	{
		printf("Solution doesn't exist\n");
		return false;
	}
	printSolution(solution);
	return true;
}



int32_t main()
{
	lage_rho();
	int maze[SIZE][SIZE]  =
	{
		{1, 1, 0, 0},
		{1, 1, 1, 1},
		{0, 0, 1, 0},
		{1, 1, 1, 1}
	};

	solveRatInMaze(maze);

	return 0;
}