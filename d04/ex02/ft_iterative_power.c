int	ft_iterative_power(int nb, int power)
{
	int	total;

	if (nb <= 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	total = 1;
	while (power >= 1)
	{
		total *= nb;
		power--;
	}
	return (total);
}
