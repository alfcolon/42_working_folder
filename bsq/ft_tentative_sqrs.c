extern int 	rows;
extern int 	cols;
extern int 	obs[25][6];
extern int 	grid[47][27];

int 	ft_topwidth(int obs_i) //record distances betweeen obs_col and top_obs_col (includes grid wall)
{
	int	obs_row;
	int	obs_col;
	int	top_obs_row;

	obs_row = obs[obs_i][0];
	obs_col = obs[obs_i][1];
	top_obs_row = obs[obs_i][0];
	while (--top_obs_row >= 0)
	{
		if (grid[top_obs_row][obs_col] == 1)
			return ((obs_row - top_obs_row) - 1);
	}
	return (obs_row);
}
int 	ft_bttmwidth(int obs_i) //record distances betweeen obs_col and bttm_obs_col (includes grid wall)
{
	int	obs_row;
	int	obs_col;
	int	bttm_obs_row;

	obs_row = obs[obs_i][0];
	obs_col = obs[obs_i][1];
	bttm_obs_row = obs[obs_i][0];
	while (++bttm_obs_row <= rows)
	{
		if (grid[bttm_obs_row][obs_col] == 1)
			return ((bttm_obs_row - obs_row) - 1);
	}
	return ((rows - obs_row) - 1);
}
int		ft_rightwidth(int obs_i) //record distances betweeen obs_col and nxt_obs_col (includes grid wall)
{
	int	obs_col;
	int	nxt_obs_col;

	obs_col = obs[obs_i][1];
	nxt_obs_col = obs[obs_i + 1][1];
	if (obs_col >= nxt_obs_col || obs[obs_i + 1] == '\0')//if last ob on row
		return ((cols - obs_col) - 1);
	return ((nxt_obs_col - obs_col) - 1);
}
int		ft_leftwidth(int obs_i) //record distances betweeen obs_col and prv_obs_col (includes grid wall)
{

	int	prv_obs_col;
	int	obs_col;

	obs_col = obs[obs_i][1];
	prv_obs_col = obs[obs_i - 1][1];
	if (obs_i == 0 ||  prv_obs_col >= obs_col)
		return (obs_col);
	return ((obs_col - prv_obs_col) - 1);
}
void	ft_tentative_surrounding_sqrs(void) //driving function for recording an obstacles distance from other obstacles to the top,left,gurrrllllll/grrrrrrr(HA!),right, and under of it
{
	int	 i;

	i = 0;
	while (i < 28)
	{
		obs[i][2] = ft_topwidth(i);
		obs[i][3] = ft_leftwidth(i);
		obs[i][4] = ft_rightwidth(i);
		obs[i][5] = ft_bttmwidth(i);
		i++;
	}
}
