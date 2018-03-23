int 	*ft_map(int *tab, int length, int (*f)(int))
{
	int 	i;

	i = 0;
	while (i++ < length)
	{
		*tab = (f)(*tab);
		tab++;
	}
	return (tab);
}
