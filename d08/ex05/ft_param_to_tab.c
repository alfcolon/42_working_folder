#include <stdlib.h>
#include "ft_stock_par.h"
/*
    int     size_param; //len of arg
    char    *str; //address of arg
    char    *copy; //copy of arg
    char    **tab; //array returned by ft_split_whitespaces
    */

char    *ft_strcpy(char *dest, char *src)
{
    int     i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
//        printf("dest[%d] = %c\n", i, dest[i]);
        i++;

    }
    dest[i] = '\0';
    return (dest);
}
void    ft_printwords(char *words)
{
    int     i;

    i = 0;
    while (words[i] != '\0')
    {
//        printf("i:\t%d\t\tword:\t%s\n", i, splitwords[i]);
        i++;
    }
}
int     ft_strlen(char *str)
{
    int     len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}
int    ft_is_delim(char *str, char *delim, int i)
{
    int     diff;
    int     len;
    int     j;

    diff = 0;
    len = ft_strlen(delim);
    j = 0;
    while(j < len)
    {
        if (str[i] == delim[j])
            diff++;
        i++;
        j++;
    }
    return (diff);
}
void    *ft_wordcpy(char *dest, char *src, int i, int len)
{
    int     j;

    j = 0;
    while (j <= len)
    {
        dest[j] = src[i];
        j++;
        i++;
    }
    dest[j] = '\0';
}
int     ft_wordlen(char *word, char *delim, int i, int strlen)
{
    int     len;

    len = 0;
    while ((i <= strlen) && (!(ft_is_delim(word, delim, i))))
    {
        len++;
        i++;
    }
    return (len);
}
char    **ft_split(char **words, char *param, char *delim)
{
    int     wordlen;
    int     count;
    int     len;
    int     i;

    words = (char **)malloc(sizeof(*words) * ft_strlen(param));
    len = ft_strlen(param);
    count = 0;
    i = 0;
    while (i < len)
    {
        if (!(ft_is_delim(param, delim, i)))
        {
            wordlen = ft_wordlen(param, delim, i, len);
            words[count] = (char *)malloc(sizeof(words) * wordlen);
            ft_wordcpy(words[count], param, i, wordlen);
            ft_printwords(words[count]);
            i += wordlen;
            count++;
        }
        i += ft_is_delim(param, delim, i);
    }
    words[count] = (char *)malloc(sizeof(words));
    words[count][0] = '\0';
    printf("\n\n%s\n\n", words[0]);
    return (words);
}
struct s_stock_par *ft_createstock(char *param)
{
    struct s_stock_par      *temp;
    char                    *tempcopy;
    char                    **temptab;
    int                     i;

    temp = malloc((sizeof(*temp) + sizeof(char) * ft_strlen(param)) + 1);
    tempcopy = (char *)malloc(sizeof(tempcopy) * ft_strlen(param) + 1);
    temptab = (char **)malloc(sizeof(*tempcopy) * ft_strlen(param) + 1);
    temp->size_param = ft_strlen(param);
    temp->str = param;
    temp->copy = tempcopy;
    temp->tab = ft_split(temptab, param, " \0");
    printf("temp->tab[0]:%s\n", temp->tab[0]);
    printf("temp->tab[0]:%s\n", temp->tab[1]);
    printf("temp->tab[0]:%s\n", temp->tab[2]);
    return temp;
}
struct s_stock_par *ft_param_to_tab(int argc, char **argv)
{
    struct s_stock_par      *arg_arr;
    int     i;

    arg_arr = malloc((sizeof(*arg_arr) + sizeof(char) * argc + 1));
    i = 0;
    while (i < argc)
    {
        arg_arr[i] = *ft_createstock(argv[i]);
        i++;
    }
    arg_arr[i].str = "\0";
    return (arg_arr);
}
