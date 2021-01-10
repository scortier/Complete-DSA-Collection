void triplet(int a[], int n, int sum)
{
	sort(a, a + n);
	for (i = 0; i < n - 2; i++)
	{
		l = i + 1; r - n - 1;
		while (l < r)

		{
			tri = a[i] + a[l] + a[r];
			if ( tri == sum)
			{	cout <<
				     return 1;
			}
			if (tri < sum) l++;
			else r--;
		}
	}
	return 0;



}