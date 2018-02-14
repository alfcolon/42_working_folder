void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;
	int	c;
	int	d;
	
	c = *a;
	d = *b;
	
	div = c / d;
	mod = c % d;
	
	*a = div;
	*b = mod;
}
