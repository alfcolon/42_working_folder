int	ft_next_prime_is(char sieve[100001], int nb)
{	
	while (++nb < 100001)
	{
		if (sieve[nb] == '1')
			return (nb);
	}
	return (1);
}
int	ft_find_next_prime(int nb)
{
	char	sieve[100001];
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < 100001)
	{
		sieve[k] = '1';
		k++;
	}
	i = 2;
	while (i < 100001)
	{
		j = i + i;
		while (j < 100001)
		{
			sieve[j] = '0';
			j += i;
		}
		i++;
	}
	return (ft_next_prime_is(sieve, nb));
}
