void	ft_putchar(char c);
void	ft_putcomb(char numarr[10][10], int size, int row, int end_char_col)
{
	int	i;
	int	cols;

	ft_putchar(numarr[row][0]);
	cols = size - 2;
	i = 1;
	while (i < size - 1)
	{
		ft_putchar(numarr[row][i]);
		i++;
	}
	ft_putchar(numarr[row][end_char_col - 1]);
	if (10 - row > size)
		ft_putchar(',');
		ft_putchar(' ');
	if (10 - row == size)
		ft_putchar('\n');
}
void	ft_find_comb(char numarr[10][10], int size, int recurssion, int recurssions)
{
	int	row;
	int	row_end;
	int	col;
	int	col_end;
	
	row = recurssion;
	row_end = 10 - size;
	while (row <= row_end)
	{
		col = size;
		col_end = 11 - row;
		while (col < col_end )
		{
			//printf("size: %d, starting row: %d, starting col:%d\n", size, row, col);
			ft_putcomb(numarr, size, row, col);
			col++;
		}
		row++;
	}
	if (recurssion > recurssions)
		ft_find_comb(numarr, size, recurssion, recurssions);
}
void	ft_printcomb1(void)
{
	int	i;
	
	i = 0;
	while (i < 9)
	{
		ft_putchar(i + '0');
		ft_putchar(',');
		ft_putchar(' ');
		i++;
	}
	ft_putchar(9 + '0');
	ft_putchar('\n');
}
void	ft_print_combn(int nb)
{
	char	numarr[10][10];
	int	i;
	int	j;
	int 	cols;

	i = 0;
	while (i < 10)
	{
		cols = 10 - i;
		j = 0;
		while (j < 10)
		{
			if (j >= cols)
				numarr[i][j] = '\0';
			else if (j < cols)
				numarr[i][j] = (j + i) + '0';
			j++;
		}
		i++;
	}
	if (nb == 1)
		ft_printcomb1();
	else
		ft_find_comb(numarr, nb, 0, nb % 10);
}
