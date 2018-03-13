#include <stdlib.h>

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
char    **ft_split(char *str, char *delim)
{
    char    **words;
    int     wordlen;
    int     count;
    int     len;
    int     i;

    len = ft_strlen(str);
    words = (char **)malloc(sizeof(*words) * len);
    count = 0;
    i = 0;
    while (i < len)
    {
        if (!(ft_is_delim(str, delim, i)))
        {
            wordlen = ft_wordlen(str, delim, i, len);
            words[count] = (char *)malloc(sizeof(words) * wordlen);
            ft_wordcpy(words[count], str, i, wordlen);
            i += wordlen;
            count++;
        }
        i += ft_is_delim(str, delim, i);
    }
    words[count] = (char *)malloc(sizeof(words));
    words[count][0] = '\0';
    int j = 0;
    while (words[j])
    {
        j++;
    }
    return (words);
}