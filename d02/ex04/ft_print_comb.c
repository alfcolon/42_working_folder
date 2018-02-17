void 	ft_putchar(char c);
void		ft_get_combs(char nums[10], int start)
{
      int	i;
      int	j;
      int	size;
      
      size = 10;
      i = start + 1;
	  	while (i <= size - 2)
	  	{
			j = i + 1;
	  	 	while (j <= size - 1)
	  	  	{
				ft_putchar(nums[start]);
	  	  	 	ft_putchar(nums[i]);
				ft_putchar(nums[j]);
	  	    		if (nums[start] < '7')
          		{
		  		    ft_putchar(',');
		  		    ft_putchar(' ');
				}
          		j++;
		    }
		    i++;
	  	}
}

void		ft_print_comb(void)
{
	char		nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
	int		start;
	
	start = 0;
	while (start < '7')
	{
	  ft_get_combs(nums, start);
	  start++;
	}
}