#include <stdlib.h>
int     ft_ultimate_range(int **range, int max, int min)
{
    int     i;
    int     size = max - min;
    range = (int **)malloc(sizeof(int *) * size);

    if (min >= max)
        return (0);
    if ((min > 2147483647) || (min < -2147483648))
        return (0);
    if ((max > 2147483647) || (max < -2147483648))
        return (0);

    i = 0;
    while (i < size)
    {
        range[i] = (int *)malloc(sizeof(int) * 2);
        range[i][0] = min;
        min++;
        i++;
    }
    return (size);
}
