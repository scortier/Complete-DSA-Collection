// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    int tt;cin>>tt;while(tt--)
#define fl(i,a,b)       for( int i=a;i<b;i++)
#define bfl(i,a,b)      for( int i=b-1;i>=a;i--)

void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/
#define SIZE 8
bool canPlace(int r, int c, int board[SIZE][SIZE])
{
	return
	    r >= 0 and r<SIZE and
	    c >= 0 and c < SIZE and
	    board[r][c] == 0;
}

bool KnightMove(int curRow, int curCol, int n, int board[SIZE][SIZE], int move_no)
{
	if (move_no == n * n)
		return true;

	int rowDir[] = { -2, -2, -1, -1, +1, +1, +2, +2};
	int colDir[] = { -1, +1, -2, +2, -2, +2, -1, +1};

	for (int curDir = 0; curDir < 8; curDir++)
	{	//in best case each place will have 8 options
		//
		int nextRow = curRow + rowDir[curDir];
		int nextCol = curCol + colDir[curDir];
		// if not visited this place before and the knight is safe to place there.
		if (canPlace(nextRow, nextCol, board) == true)
		{
			//place the knight
			board[nextRow][nextCol] = move_no + 1; //move_no = moves done before
			bool isSuccessful = KnightMove(nextRow, nextCol, n, board, move_no + 1);
			if (isSuccessful)
				return true;
			else
			{
				//jha par knight rakha tha vha se hta do
				board[nextRow][nextCol] = 0; //erase the knight
			}
		}
	}
	return false; // saari condn check kar li par kahi nahi chl sakte
}

void printBoard(int board[SIZE][SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void solve()
{
	int board[SIZE][SIZE] = {0};
	int n; cin >> n;

	bool ans = KnightMove(0, 0, n, board, 1);
	if (ans == true)
	{
		printBoard(board, n);
	}
	else
	{
		cout << "Beta tumse se kuch na hopaega!";
	}

}

int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}