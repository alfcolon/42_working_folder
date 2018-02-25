#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}
void	ft_putstr(char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}
void	ft_print_params(int argc, char **argv, int *params)
{
    int	i;

    i = 0;
    while (i < argc - 1)
    {
        ft_putstr(argv[params[i]]);
        ft_putchar('\n');
        i++;
    }
}

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while ((s1[i]) || (s2[i]))
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
void	ft_sort_params(int argc, char **argv, int *params)
{
    int     a;
    int     b;
    int	    temp;
    int	    sorted;

    sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        a = 0;
        b = 1;
        while (b < argc - 1)
        {
            if ((ft_strcmp(argv[params[a]], argv[params[b]]) > 0))
            {
                temp = params[a];
                params[a] = params[b];
                params[b] = temp;
                sorted = 0;
            }
            a++;
            b++;
        }
    }
    ft_print_params(argc, argv, params);
}

int	main(int argc, char **argv)
{
    int    i;
    int    params[20];

    i = 1;
    while (i < argc)
    {
        params[i - 1] = i;
        i++;
    }
    ft_sort_params(argc, argv, params);
    return (0);
}
