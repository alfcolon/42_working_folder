int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
	{
		return (ft_recursive_factorial(nb - 1) * nb);
	}
	return (1);
}
