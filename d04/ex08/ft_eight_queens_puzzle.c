/*numberphile == 92 source*/
int	ft_eight_queens_puzzle(void)
{
	return (92);
}
/*
int		board[8], count;

int		ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
int		place(int row, int column)
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
    			count++;
    		ft_test_queen(row + 1, n);
		}
		++column;
	}
}
int		ft_eight_queens_puzzle(void)
{
	int		row;
	int		size;
	
	row = 1;
	size = 8;
	ft_test_queen(row, size);
	return (count);
}
*/