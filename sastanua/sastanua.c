#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_print_row(int start, int end)
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
void    ft_print_door_end(int start, int end)
{
    int i;

    i = start;
    while (i <= end)
    {
//        printf("end:%d\n", i);
        if (i == end)
        {
            ft_putchar('\\');
        }
        else if (i < end)
        {
            ft_putchar('*');
        }
        i++;
    }
    ft_putchar('\n');
}
void    ft_print_door_start(int start, int door_start)
{
    int i;

    i = 0;
    while (i < door_start)
    {
        if (i == start)
        {
            ft_putchar('/');
        }
        else if (i > start)
        {
            ft_putchar('*');
        }
        else
        {
            ft_putchar(' ');
        }
        i++;
    }
}
void    ft_print_door(int door_start, int door_end)
{
    int i;

    i = door_start;
    while (i <= door_end)
    {
        ft_putchar('|');
        i++;
    }
}
int     ft_door_height(int limit)
{
    int     height;
    int     i;

    height = 1;
    i = 0;
    while (i < limit)
    {
        height += 2;
        i++;
    }
    return (height);
}

void    ft_build_door(int total_stacks, int start, int end)
{
    int     door_start;
    int     door_end;
    int     door_height;
    int     rows;
    int     i;

    rows = 3 + (total_stacks - 1);
    door_height = ft_door_height(((total_stacks - 1) / 2));
    door_start = end - ((end - start)  / 2) - (door_height / 2);
    door_end = door_start + door_height - 1;
//    door_start = (((end - start) / 2)  - (door_height / 2);
//    door_end = (((end + 2) - start) / 2)  + (door_height / 2);
//    printf("end:%d\n", end);
    i = 0;
    while (i < door_height)
    {
        if ((door_height >= 5) && (i == (door_height / 2)))
        {
            ft_print_door_start(start, door_start);
            ft_print_door(door_start, door_end - 2);
            ft_putchar('$');
            ft_putchar('|');
            ft_print_door_end(door_end + 1, end);
        }
        else
        {
            ft_print_door_start(start, door_start);
            ft_print_door(door_start, door_end);
            ft_print_door_end(door_end + 1, end);
        }
        start--;
        end++;
        i++;
    }
}
void    ft_buildrow(int total_stacks, int basewidth)
{
    int	    start;
    int 	end;
    int     row;
    int	    total_rows;
    int     stack;

    start = (basewidth / 2) - 1;
    end = start + 2;
    stack = 0;
    while (stack < total_stacks)
    {
        row = 0;
        total_rows = 3 + (stack);
//        printf("totalrows:%d\n",total_rows);
        while (row < total_rows)
        {
            if ((stack == total_stacks - 1) && (row == (total_rows - (ft_door_height((total_stacks - 1) / 2)))))
            {
//                printf("row:%d\n",row);
                ft_build_door(total_stacks, start, end);
                break;
            }
            else
                ft_print_row(start--, end++);
                row++;
        }
        start -= (1 + (stack/2));
        end += (1 + (stack/2));
        stack++;
    }
}
int     ft_find_basewidth(int stack_size)
{
    int     first_row;
    int     basewidth;
    int     stack;
    int     row_count;

    first_row = 3;
    basewidth = 7;
    stack = 1;
    while (stack < stack_size)
    {
        first_row = basewidth + ((3 + (stack/2)) * 2);
        row_count = 3 + stack;
        basewidth = first_row + (2 * (row_count - 1));
        printf("firstrow:%d\t\t\tstack:%d\t\t\tbasewidth:%d\n",first_row,stack,basewidth);
        stack++;
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
void    ft_sastanua(char *size)
{
    int	stack_size;
    int	basewidth;

    stack_size = ft_atoi(size);
    basewidth = ft_find_basewidth(stack_size);
    ft_buildrow(stack_size, basewidth);
}
int     main(void)//for testing
{
    ft_sastanua("4");
    return (0);
}
