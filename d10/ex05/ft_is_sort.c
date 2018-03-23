int 	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int 	ascending;
	int 	descending;
	int 	direction;
	int 	i;

	ascending = 0;
	descending = 0;
	i = 0;
	while(tab[i + 1])
	{
		direction = (*f)(tab[i], tab[i + 1]);
		if (ascending == 0 && descending == 0)
			if (direction == 1)
				ascending = 1;
			else if(direction == -1)
				descending = 1;
		if (ascending == 1 && direction == -1)
			return (0);
		else if (descending == 1 && direction == 1)
			return (0);
		i++;
	}
	return (1);
}
