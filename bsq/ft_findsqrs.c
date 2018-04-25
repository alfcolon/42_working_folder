#include <stdio.h>
extern int 	count;
extern int 	sqr;
extern int 	obs[25][6];
extern int 	grid[47][27];

int 	ft_find_topleftobs(int obs_i)
{
	int	obs_col;
	int	obs_row;
	int	end_col;

	obs_col = obs[obs_i][1];
	obs_row = obs[obs_i][0];
	end_col = obs_col - obs[obs_i][3];
	while (obs_row >= 0)
	{
		while(--obs_col >= end_col)
		{
			if (grid[obs_row][obs_col] == 1)
				return (obs_col);
		}
		--obs_row;
	}
	return (0);

}
int 	ft_validsqr_left(int obs_i)
{
	int	width;
	int	top_left_obs_row;
	int	obs_col;
	int 	row_start;
	int	col_start;

	width = obs[obs_i][3];
	top_left_obs_row = ft_find_topleftobs(obs_i);
	obs_col = obs[obs_i][1];
	row_start = top_left_obs_row;
	while (++row_start <= ((top_left_obs_row + width) - 1))
	{
		col_start = obs_col - width;
		while (++col_start <= (obs_col - 1))
		{
			if (grid[row_start][col_start] == 1)
				return (0);
		}
	}
	return (1);
}
int 	ft_find_toprightobs(int obs_i)
{
	int	obs_col;
	int	obs_row;
	int	end_col;

	obs_col = obs[obs_i][1];
	obs_row = obs[obs_i][0];
	end_col = obs_col + obs[obs_i][4];
	while (obs_row >= 0)
	{
		while(++obs_col >= end_col)
		{
			if (grid[obs_row][obs_col] == 1)
				return (obs_col);
		}
		--obs_row;
	}
	return (0);
}
int 	ft_validsqr_right(int obs_i)
{
	int	width;
	int	top_right_obs_row;
	int	obs_col;
	int 	row_start;
	int	col_start;

	width = obs[obs_i][4];
	top_right_obs_row = ft_find_toprightobs(obs_i);
	obs_col = obs[obs_i][1];
	row_start = top_right_obs_row;
	while (++row_start <= ((top_right_obs_row + width) - 1))
	{
		col_start = obs_col;
		while (++col_start <= (obs_col + width))
		{
			if (grid[row_start][col_start] == 1)
				return (0);
		}
	}
	return (1);
}
int 	ft_find_leftbttmobs(int obs_i)
{
	int	obs_col;
	int	obs_row;

	obs_col = obs[obs_i][1];
	obs_row = obs[obs_i][0];
	while (--obs_col >= 0)
	{
		while(++obs_row >= 0)
		{
			if (grid[obs_row][obs_col] == 1)
				return (obs_col);
		}
	}
	return (0);

}
int 	ft_validsqr_bttm(int obs_i)
{
	int	width;
	int	left_obs_col;
	int	obs_row;
	int 	row_start;
	int	col_start;

	width = obs[obs_i][5];
	left_obs_col = ft_find_leftbttmobs(obs_i);
	obs_row = obs[obs_i][0];
	row_start = obs_row;
	while (++row_start <= (obs_row + width))
	{
		col_start = left_obs_col;
		while (++col_start <= (left_obs_col + width))
		{
			if (grid[row_start][col_start] == 1)
				return (0);
		}
	}
	return (1);
}
int 	ft_find_lefttopobs(int obs_i)
{
	int	obs_col;
	int	obs_row;

	obs_col = obs[obs_i][1];
	obs_row = obs[obs_i][0];
	while (--obs_col >= 0)
	{
		while(--obs_row >= 0)
		{
			if (grid[obs_row][obs_col] == 1)
				return (obs_col);
		}
	}
	return (0);

}
int 	ft_validsqr_top(int obs_i)
{
	int	width;
	int	left_obs_col;
	int	obs_row;
	int 	row_start;
	int	col_start;

	width = obs[obs_i][2];
	left_obs_col = ft_find_lefttopobs(obs_i);
	obs_row = obs[obs_i][0];
	row_start = obs_row - width;
	while (row_start < obs_row)
	{
		col_start = left_obs_col;
		while (++col_start <= (left_obs_col + width))
		{
			if (grid[row_start][col_start] == 1)
				return (0);
		}
		row_start++;
	}
	return (1);
}
void	ft_findsqrs(void) //for now, iterate through all possible squares and validate them
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (obs[i][2] > sqr)//top, get left obstacle column check if square can fit to the top-right
			if (ft_validsqr_top(i))
			{
				printf("obs:[%d,%d], sqr_width:%d, direction:%s\n", obs[i][0],obs[i][1],obs[i][2],"up");
				sqr = obs[i][2];
			}
		if (obs[i][3] > sqr)//left
			if (ft_validsqr_left(i))
			{
				printf("obs:[%d,%d], sqr_width: %d, direction:%s\n", obs[i][0],obs[i][1],obs[i][3],"left");
				sqr = obs[i][3];
			}
		if (obs[i][4] > sqr)//right
			if (ft_validsqr_right(i))
			{
				printf("obs:[%d,%d], sqr_width: %d, direction:%s\n", obs[i][0],obs[i][1],obs[i][4],"right");
				sqr = obs[i][4];
			}
		if (obs[i][5] > sqr)//bttm
			if (ft_validsqr_bttm(i))
			{
				printf("obs:[%d,%d], sqr_width: %d, direction:%s\n", obs[i][0],obs[i][1],obs[i][5],"down");
				sqr = obs[i][5];
			}
		i++;
	}
}

