 #include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str++);
	}
}
void	ft_print_params(int argc, char **argv)
{
	int	i;
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}
int	main(int argc, char **argv)
{
	int	i;
	
	if (argc <= 1)
		return (0);
	ft_print_params(argc, argv);
	
	return (0);
}
