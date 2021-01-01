//2 ptr method
void revarray2ptr(int a[], int start, int end)
{
	int i = 0, j = n - 1;
	while (end > start)
	{
		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
	for (int i = 0; i < a.size(); i++)
	{
		/* code */cout << a[i] << " "	;
	}
}


// recursive approach
void revarr(int a[], int start, int end)
{
	int i = 0, j = n - 1;


	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	i++;
	j--;

	revarr(a, start + 1, end - 1);
	for (int i = 0; i < n; ++i)
	{
		/* code */cout << a[i] << " "	;
	}
}

void solve()
{
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	revarray2ptr(a, 0, n - 1);

}