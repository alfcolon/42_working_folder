int		ft_find_sqroot(int nb, int left_limit, int mid, int right_limit)
{
	int		mid_sqrd;
	int		left_sqrd;
	
	mid_sqrd = mid * mid;	
	while (mid_sqrd > nb)
	{
		right_limit = mid;
		mid = (right_limit - left_limit) / 2;
	}
	left_limit = mid;
	while (left_limit <= right_limit)
	{
		left_sqrd = left_limit * left_limit;
		if (left_sqrd == nb)
		{
			return (left_limit);
		}
		left_limit++;
	}
	return (0);
}
int		ft_sqrt(int nb)
{
	int		left_limit;
	int		right_limit;
	int 		mid;
	int		sqroot;
	
	if ((nb < 3) || (nb > 2147483647))
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	left_limit = 2;
	if (nb > 46340 * 2)
		right_limit = 46340;
	else
		right_limit = nb / 2;
	mid = (right_limit - left_limit) / 2;
	sqroot = ft_find_sqroot(nb, left_limit, mid, right_limit);
	return (sqroot);
}
int	main()
{
	ft_sqrt(4);
	return (0);
}
