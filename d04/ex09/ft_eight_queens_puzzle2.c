int	board[8], count;

count = 0;

void	ft_putchar(char c);

void	print(int n)
{
	int		i;
	int		j;
	
	i = 1;
	while (i < 9)
	{
		j = 1;
		while (j < 9)
		{
			if (board[i] == j)
			{
				ft_putchar(j + '0');
			}
			j++;

		}
		i++;
	}
	if (count == 92)
		ft_putchar(10);
	ft_putchar('\n');
}
int		ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
int	place(int row, int column)
{
	int i;
 
	i = 1;
	while (i <= row - 1)
	{
		if(board[i] == column)
			return 0;
		else
			if (ft_abs(board[i] - column) == ft_abs(i - row))
				return 0;
		++i;
	}
	return 1;
}
void	ft_test_queen(int row, int n)
{
	int column;
	
	column = 1;
	while (column <= n)
	{
		if (place(row,column))
		{
			board[row] = column;
			if (row == n)
    			print(n);
			else
    			ft_test_queen(row + 1, n);
		}
		++column;
	}
}
void	ft_eight_queens_puzzle2(void)
{
	int		row;
	int		size;
	
	row = 1;
	size = 8;
	ft_test_queen(row, size);
}
