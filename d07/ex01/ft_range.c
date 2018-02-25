#include <stdlib.h>
int     *ft_range(int min, int max)
{
    int     *range;
    int     i;

    if (min >= max)
        return (0);
    if ((min > 2147483647) || (min < -2147483648))
        return (0);
    if ((max > 2147483647) || (max < -2147483648))
        return (0);
    range = (int *)malloc(sizeof(int) + ((max - min) + 2));
    i = 0;
    while (++min < max)
    {
        range[i] = min;
    }
    return (range);
}
