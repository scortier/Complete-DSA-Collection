int is_prime[1000001];

void sieve()
{
	int mod = 1000000;
	for (int i = 1; i <= mod; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;

	for (int i = 2; i * i <= mod; i++)
	{
		if (is_prime[i] == 1)
		{
			for (int i = 2; i * i <= mod; j += i)
				is_prime[j] = 0;
		}
	}
}