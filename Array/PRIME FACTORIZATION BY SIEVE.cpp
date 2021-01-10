int a[1000001];
void p_sieve()
{
	int max = 1000000;
	for (int i = 1; i <= max; i++) a[i] = -1;

	for (int i = 2; i <= max; i++)
	{
		if (a[i] == -1)
		{
			for (int j = i; j <= max; j += i)
				if (a[j] = -1)
					a[j] = i;
		}
	}
}