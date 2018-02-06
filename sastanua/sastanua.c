#include <stdio.h>
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_build_row(int start, int end)
{
	int	i;
	
	i = 0;
	while (i < end + 1)
	{
		if (i == start)
		{
			ft_putchar('/');
		}
		else if ((i > start) && (i < end))
		{
			ft_putchar('*');
		}
		else if (i == end)
		{
			ft_putchar('\\');
			ft_putchar('\n');
		}
		else
			ft_putchar(' ');
		i++;
	}
}

void	ft_sastanua(int stack_size, int basewidth)
{

	int	stack;
	int	row;
	int	rows;
	int	start;
	int	end;
	
	stack = 1;
	row = 1;
	rows = 3;
	start = (basewidth / 2) + 1;
	end = start + 2;
	while (stack <= stack_size)
	{
		while (row <= rows)
		{
			if ((row == rows) && (stack + 1 <= stack_size))
			{
				ft_build_row(start, end);
				stack++;
				row -= row;
				rows += 1;
				start -= 2;
				end += 2;
			}	
			else if ((row == rows) && (stack == stack_size))
			{
				ft_build_row(start, end);
				break;
			}
			else
				ft_build_row(start, end);
				start--;
				end++;
				row++;
	
		}
		if ((row == rows) && (stack + 1 > stack_size))
		{
			break;
		}
	}
}
int	ft_find_basewidth(int stack_size)
{
	int	stack_rows;
	int	rows;
	int	basewidth;
	
	stack_rows = 3;
	rows = 3;
	basewidth = 0;
	
	while (stack_size > 0)
	{
		if (basewidth == 0)
		{
			basewidth = 3;
			rows--;
		}
		else if ((rows == 0) && ((stack_size - 1) > 0))
		{
			stack_size--;
			stack_rows++;
			rows += stack_rows - 1;
			basewidth += 4;
		}
		else if ((rows == 0) && ((stack_size - 1) == 0))
		{
			break;
		}				 
		basewidth += 2;
		rows--;
	}
	return (basewidth);
}
int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	answer;

	sign = 1;
	result = 0;
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
	{
		str++;
	}
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;	
	}
	while((*str >= '0') && (*str <= '9'))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	answer = sign * result;
	return (answer);
}
int	main(int argc, char *argv[])
{
	int	stack_size;
	int	basewidth;
	
	stack_size = ft_atoi(argv[1]);
	basewidth = ft_find_basewidth(stack_size);
	if (argc < 2)
	{
		write (2, "Error, stack count needed.", 26);
		return (0);
	}
	printf("stacksize is: %d, basewidth is:%d\n", stack_size, basewidth);
	ft_sastanua(stack_size, basewidth);
	return (0);
}	
