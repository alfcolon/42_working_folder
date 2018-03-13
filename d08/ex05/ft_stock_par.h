#ifndef FT_STOCK_PAR_H
#define FT_STOCK_PAR_H

char    **ft_split_whitespaces(char *str, char **tab);
//void    ft_show_tab(struct s_stock_par *par);

typedef struct s_stock_par
{
    int     size_param; //len of arg
    char    *str; //address of arg
    char    *copy; //copy of arg
    char    **tab; //array returned by ft_split_whitespaces
}t_stock_par;
#endif FT_STOCK_PAR_H
