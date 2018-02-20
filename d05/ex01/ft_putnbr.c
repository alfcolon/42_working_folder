void	ft_putchar(char c);
void	ft_putnbr(int nb)
{
	if ((nb <= 2147483647) && (nb >= -2147483648))
	{
		if (nb > 0)
			ft_putchar('-');
			nb *= -1;
		else if ((nb >= 0) && (nb <= 0))
			ft_putchar(nb + '0');
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
