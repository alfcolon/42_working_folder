void	ft_putchar(char c);
int  ft_print_pairs(char n1, char n2, char n3, char n4)
{
	ft_putchar(n1);
	ft_putchar(n2);
	ft_putchar(' ');
	ft_putchar(n3);
	if ((n1 == '9') && (n2 == '8'))
	{
		if ((n3 == '9') && (n4 == '9'))
		{
			ft_putchar(n4);
			return (0);
		}
	}
	ft_putchar(n4);
	ft_putchar(',');
	ft_putchar (' ');
	return (1);
}
void	ft_get_2nd_pair(char nums[10], int n1, int n2)
{
	int	n3;
	int	n4;

	n3 = n1;
	while (n3 < 10)
	{
		if (n3 == n1)
		{
			n4 = n2 + 1;
		}
		else
			n4 = 0;
		while (n4 < 10)
		{
			ft_print_pairs(nums[n1], nums[n2], nums[n3], nums[n4]);
			n4++;
		}
		n3++;
	}
}	
void	ft_print_comb2(void)
{
	char	nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
	int	n1;
	int	n2;

	n1 = 0;
	while (n1 < 10)
	{
		n2 = 0;
		while (n2 < 10)
		{ 
			ft_get_2nd_pair(nums, n1, n2);
			n2++;
		}
		n1++;
	}
}	
