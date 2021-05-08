bool isValid(board[][], int row, int col, int val)
{
	//row m check karna hai so col change honge row wil remain fixed
	for (int j = 0; j < board[0].size(); j++)
		if (board[row][j] == val)
			return false;

//y col k saare rows dehenge
	for (int i = 0; i < board.size(); i++)
		if (board[i][col] == val)
			return false;

//check for submatrix
	// i,j --> 3*i/3,3*j/3
	//ex: 4,7(koi bhi ek pt hai us submatrix m)--> 3*4/3=3*(1)=3  , 3*7/3=3*2=6 y top left kona milga us submatrix ka
	int submatrix_i = row / 3 * 3;
	int submatrix_j = col / 3 * 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (board[submatrix_i + i][submatrix_j + j] == val)
				return false;
		}
	}
}

void util(int board[][], int i, int j)
{

	if (i == arr.size()) {
		display(board);
		return;

	}
	int next_i = 0;
	int next_j = 0;

	if (j == board[0].size() - 1) //last col p hai toh
	{
		next_i = i + 1; //next row par shift kardo
		next_j = 0;	//and first col of next row se start hoga
	}
	else //agr last col pr nhi hai
	{
		next_i = i; 	//row vhi rhegi
		next_j = j + 1;	//col badd jaega
	}
	//if pehle se non zero val padi ai so aae jao
	if (board[i][j] != 0)
		util(board, next_i, next_j);
	//agr zero val hai
	else {
		for (int possible_option = 1; possible_option <= 9; possible_option++)//possible options hai naaki real options
		{
			//to check for real options
			if (isValid(board, i, j, possible_option) == true) {
				board[i][j] = possible_option;
				util(board, next_i, next_j); //call for next box
				board[i][j] = 0;	//backtrack
			}
		}

	}


}


///for interview bit

bool is_valid(vector<vector<char>>&A, int row, int col, char x)
{
	for (int i = 0; i < 9; i++)
	{
		if (A[i][col] == x)
		{
			return false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (A[row][i] == x)
		{
			return false;
		}
	}
	int curr_row = (row / 3) * 3, curr_col = (col / 3) * 3;
	for (int i = curr_row; i < curr_row + 3; i++)
	{
		for (int j = curr_col; j < curr_col + 3; j++)
		{
			if (A[i][j] == x)
			{
				return false;
			}
		}
	}
	return true;
}
void helper(vector<vector<char>>&ans, vector<vector<char>>A, int i, int j)
{
	if (i == 9)
	{
		ans = A;
		return;
	}
	int next_i, next_j;
	if (j == A[0].size() - 1)
	{
		next_i = i + 1;
		next_j = 0;
	}
	else
	{
		next_i = i;
		next_j = j + 1;
	}
	if (A[i][j] != '.')
	{
		helper(ans, A, next_i, next_j);
	}
	else
	{
		for (char x = '1'; x <= '9'; x++)
		{
			if (is_valid(A, i, j, x))
			{
				A[i][j] = x;
				helper(ans, A, next_i, next_j);
				A[i][j] = '.';
			}
		}
	}
}
void Solution::solveSudoku(vector<vector<char>> &A)
{
	vector<vector<char>>ans;
	helper(ans, A, 0, 0);
	A = ans;
}



util(ans, board, i, j)
{
	if (i == board.size())
	{
		ans.push_back();
		return;
	}


}