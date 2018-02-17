int	ft_iteratative_factorial(int nb)
{
	int	total;
	
	total = 1;
	while (nb > 0)
	{
		total *= nb;
		nb--;
	}
	return (total);
}	
