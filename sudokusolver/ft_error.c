int 	givens = 0;
int 	ft_vals(int row, int col, int num, int update)
{
	static int 	rows[10][10];
	static int 	cols[10][10];
	static int 	squares[3][3][10];

	if (update == 0)
		if (rows[row][num] == 0)
			if (cols[col][num] == 0)
				if (squares[row / 3][col / 3][num] == 0)
				{
					rows[row][num] = 1;
					cols[col][num] = 1;
					squares[row / 3][col / 3][num] = 1;
					givens++;
					return 1;
				}
	if (update == 1)
	{
		rows[row][num] = 0;
		cols[col][num] = 0;
		squares[row / 3][col / 3][num] = 0;
		return 1;
	}
	return (0);
}
int 	ft_error(int argc, char **argv)
{
	int	i;
	int	j;

	(void)argc;
	i  = 0;
	while (++i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				if (!(ft_vals(i - 1, j, argv[i][j] - '0', 0)))
					return 0;
			j++;
		}
	}
	if (givens < 17)
		return (0);
	return (1);
}
