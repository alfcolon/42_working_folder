#include <stdlib.h>

char    *ft_paramscat(char *dest, char **argv)
{
    int     i;
    int     j;
    int     k;

    i = 1;
    j = 0;
    while (argv[i])
    {
        k = 0;
        while(argv[i][k])
        {
            dest[j] = argv[i][k];
            k++;
            j++;
        }
        dest[j++] = '\\';
        dest[j++] = 'n';
        i++;
    }
    printf("%s\n", dest);
    return (dest);
}
int     ft_params_len(char **argv)
{
    int     i;
    int     j;
    int     len;

    len = 0;
    i = 1; //skip file name
    while (argv[i])
    {
        j = 0;
        while(argv[i][j])
        {
            len++;
            j++;
        }
        i++;
    }
    printf("len: \t%d\n", len);
    return len;
}
char    *ft_concat_params(int argc, char **argv)
{
    int     len;
    int     i;
    int     newlinecharcount;
    char    *concatedparams;

    len = ft_params_len(argv);
    newlinecharcount = (argc - 1) * 2;
    concatedparams = (char *)malloc(sizeof(concatedparams) * ((argc - 1) * (newlinecharcount + len)));
    ft_paramscat(concatedparams, argv);

    return(concatedparams);
}
