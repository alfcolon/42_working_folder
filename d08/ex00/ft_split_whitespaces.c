#include <stdlib.h>
#include <stdio.h>
//change to have word arr return [word i-position, word len],[word i-position, word len] and change up the flow from there
void    ft_printwords(char **splitwords)
{
    int     i;

    i = 0;
    while (splitwords[i] != "\0")
    {
        printf("i:\t%d\t\tword:\t%s\n", i, splitwords[i]);
        i++;
    }
}
void    ft_wordcpy(char *dest, char *src, int *wordarr, int word_posx, int len)
{
    int     i;

    i = 0;
    while (i < len)
    {
        dest[i] = src[wordarr[word_posx]];
        i++;
        word_posx++;
    }
    dest[i] = '\0';
}
int     ft_word_len(int *wordarr, int word_position)
{
    int     next_letter_position;
    int     len;

    len = 0;
    while (1)
    {
        len++;
        next_letter_position = wordarr[word_position + 1];
        if (next_letter_position != wordarr[word_position] + 1)
            break;
        word_position++;
    }
    return (len);
}
char    **ft_record_words(char **splitwords, int *wordarr, char *str)
{
    int     word_count;
    int     len;
    int     word_position;
    int     i;

    word_position = 2;
    word_count = wordarr[0];
    i = 0;
    while (i < word_count)
    {
        len = ft_word_len(wordarr, word_position);
        splitwords[i] = (char *)malloc(sizeof(splitwords[i]) * (len + 1));
        printf("word_n\n");
        ft_wordcpy(splitwords[i], str, wordarr, word_position, len);
        i++;
        word_position += len;
    }
    splitwords[i] = (char *)malloc(sizeof(splitwords[i]) * (1));
    splitwords[i] = "\0";
    return (splitwords);
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
int     ft_strcmp(char *str, char *delim, int i, int len)
{
    int     j;
    int     k;

    k = i;
    j = 0;
    while (j < len)
    {
        if (str[k] != delim[j])
            return (0);
        k++;
        j++;
    }
    return (1);
}
void    *ft_get_word_position(int *wordarr, int len, char *str, char *delim)
{
    int i, j;
    int count;
    int totalcount;

    len = ft_strlen(delim);
    count = 0;
    totalcount = 0;

    i = 0;
    j = 2;
    while (str[i]) {
        if (!(ft_strcmp(str, delim, i, len)))//if the *str is not a deliminator, get it's length
        {
            count += 1;
            while ((!(ft_strcmp(str, delim, i, len))) && i < 20) {
                printf("word position i:\t%d\n", i);
                wordarr[j] = i;
                totalcount++;
                j++;
                i++;
            }
        }
        i += len;
    }
    wordarr[0] = count;
    wordarr[1] = totalcount;
}
char    **ft_split_whitespaces(char *str)
{
    char    *delim = " ";
    int     *wordarr = (int *)malloc(sizeof(wordarr) * 100);
    char    **splitwords;
    int     len;
    int     char_count;

    len = ft_strlen(delim);
    ft_get_word_position(wordarr, len, str, delim);
    char_count = wordarr[1];
    //returns array with 0-posx as the count and 1-posx as the total count (used as size for mllov csll
    splitwords = (char **)malloc(sizeof(*splitwords) * (char_count + 1));//return array
    if (char_count > 0)
    {
        ft_record_words(splitwords, wordarr, str);
        ft_printwords(splitwords);
        return (splitwords);
    }
    printf("len:\t%d\ncount:\t%d\ntotalcount:\t%d\n\n", len, wordarr[0], wordarr[1]);

    return NULL;
}
int     main(void)
{
    ft_split_whitespaces("Ne J JE", " ");
    return (0);
}



