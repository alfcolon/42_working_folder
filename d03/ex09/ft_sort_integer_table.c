void	ft_sort_integer_table(int *tab, int size)
{
	int		a;
	int 	b;
	int		temp;
	int		sorted;
	
	sorted = 0;
	while (sorted == 0)
	{	
		sorted = 1;
		a = 0;
		b = a + 1;
		while (a < size - 1)
		{
			if (tab[a] > tab[b])
			{
				temp = tab[a];
				tab[a] = tab[b];
				tab[b] = temp;
				sorted = 0;
			}
			a++;
			b++;
		}
	}
}