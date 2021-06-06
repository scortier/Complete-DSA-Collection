int dp0[n + 1];
int dp1[n + 1];

dp0[1] = 1;
dp1[1] = 1;

for (int i = 2; i < n; i++)
{
	dp1[i] = dp1[i - 1] + dp0[i - 1];
	dp0[i] = dp1[i - 1];
}
return (dp1[n] + dp0[n]);




//alter
int old_ones = 0, old_zeroes = 0;

for (int i = 2; i <= n; i++)
{
	int new_zeroes = old_zeroes;
	int new_ones = old_zeroes + old_ones;

	old_ones = new_ones;
	old_zeroes = new_zeroes;
}

return (old_zeroes + old_ones);