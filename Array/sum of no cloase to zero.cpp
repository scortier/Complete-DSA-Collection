void sum(int a[], int n)
{
	int maxm = INT_MAX; l = 0; r = n - 1; min_l = 0; min_r = n - 1;
	int curr = a[l] - a[r];
	if (abs(curr) < abs(maxm))
	{
		curr = maxm;
		min_l = l;
		min_r = r;
	}
	if (curr < 0)
		l++;
	else r--;
}