int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char *ft_strrev(char *str)
{
	int i;
	int len;
	char temp;
	
	i = 0;
	len = ft_strlen(str) - 1;
	while(i <= len)
	{
		temp = str[len];
		str[len] = str[i];
		str[i] = temp;
		i++;
		len--;
	}
	return(str);
}	
