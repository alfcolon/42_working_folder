#include <unistd.h>
#define SIZE 10

void	ft_get_combs(char nums[SIZE], int start, int end)
{
      int i;
      int j;
    
      i = start + 1;
	  	while (i <= SIZE - 2)
	  	{
	  	  j = i + 1;
	  	  while (j <= SIZE - 1)
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

void	ft_print_comb(void)
{
	char	nums[SIZE] = {'0','1','2','3','4','5','6','7','8','9'};
	int	start;
	int	end;
	
	start = 0;
	end = 2;
	while (start < '7')
	{
	  ft_get_combs(nums, start, end);
	  start++;
	  end++;
	}
}
