#include <unistd.h>

int 	board[10][10];
int 	row;
int 	col;

int	ft_error(int, char **);
int 	ft_vals(int, int, int, int);

void	ft_putchar(char c)
{
	write(1,&c,1);
}
void	ft_printboard(void)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(board[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
int 	ft_findcell(int update)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (board[i][j] == 0)
			{

				if (update)
				{
					row = i;
					col = j;
				}
				return (1);
			}
			j++;
		}
		i++;
	}
	return 0;
}
int 	ft_play(int r, int c)
{
	int 	num;
	int 	nextsqr;
	int 	solved;

	nextsqr = ft_findcell(0);
	if (!nextsqr)//check for first avail square
		return (1);
	num = 1;
	while (num <= 9)
	{
		if (ft_vals(r, c, num, 0)) //if the num is a valid solution
		{
			board[r][c] = num; //update board
			ft_findcell(1);//find next square
			solved = ft_play(row,col);//test the next step
			if (solved)//if the test works, return 1
				return 1;
			board[r][c] = 0;//else set the value of the square to 0
			ft_vals(r, c, num, 1);//free the number, free the world
		}
		num++;
	}
	return (0);
}
void	ft_buildboard(int argc, char **argv)
{
	int 	i;
	int 	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				board[i - 1][j] = 0;
			else
				board[i - 1][j] = argv[i][j] - '0';
			j++;
		}
	}
}
void	ft_sudoku(int argc, char **argv)
{
	ft_buildboard(argc, argv);
	ft_findcell(1);
	ft_play(row, col);
	ft_printboard();
}
int 	main(int argc, char **argv)
{
	(void)argc;
	if (!(ft_error(argc, argv)))
	{
		write(2,"Error\n",6);
		return 0;
	}
	ft_sudoku(argc, argv);
	return (0);
}
