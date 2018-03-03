#include <stdlib.h>

int     ft_is_letter(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return (1);
    if ((c >= 'a') && (c <= 'z'))
        return (1);
    return (0);
}
int     *ft_word_count(char *str)
{
    int     *words = (int *)malloc(sizeof(words) * 100);
    int     i;
    int     w;

    words[0] = 0;//stores the word count in the 0 first element in the arr.
    w = 1;
    i = 0;
    while (str[i])
    {
        if (ft_is_letter(str[i]))
        {
            words[0]++;
            words[w++] = i;
            while (ft_is_letter(str[i]))
            {
                i++;
            }
            words[w++] = i - 1;
        }
        i++;
    }
    return (words);
}
char    *ft_strcpy(char *dest, char *src, int i, int j, int k)
{
    while (i <= j)
    {
        *dest++ = src[i];
        printf("array: %d\tsrc[%d] = %c\n",k, i, src[i]);
        i++;
    }
    return (dest);
}

char    **ft_split_whitespaces(char *str)
{
    int     start;
    int     j;
    int     *wordinfo;
    int     word_count;
    char    **words;

    wordinfo = ft_word_count(str);
    word_count = wordinfo[0];
    words = (char **)malloc(sizeof(*words) * (word_count + 1));
    start = 1;
    j = 0;
    while (j <= word_count)
    {
        if (j == word_count)
            words[j] = (char *)malloc(sizeof(words[j]) * (1));
        words[j] = (char *)malloc(sizeof(words[j]) * (wordinfo[start + 1] - wordinfo[start]));
        ft_strcpy(words[j],str,wordinfo[start], wordinfo[start + 1], j);
        start += 2;
        j++;
    }
    return (words);
}
