//O(n^2)
void reverse(int a[r][c])
{
	for (i = 0; i < r; i++)
	{
		for (j = 0, k = c - 1; j < k; j++, k--) //dono corner se ek ek karke swap .
			swap(a[i][j], a[i][k]);
	}
}
void transpose(int a[r][c])
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			swap(a[i][j], a[j][i]);
		}
	}
}


//