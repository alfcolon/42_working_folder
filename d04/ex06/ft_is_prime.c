int	ft_is_prime(int nb)
{
	int	i;
	int	prime;
	
	if (nb < 2)
	{
		return (0);
	}
	if (nb == 2)
	{
		return (1);
	}
	prime = nb/2;
	i = 3;
	while (i <= prime)
	{
		if ((nb/i) % 2 == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
