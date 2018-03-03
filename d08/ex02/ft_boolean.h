#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#define TRUE 1
#define FALSE 0
#define EVEN(n) ((n % 2) == 0)
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD(n) ((n % 2) == 1)
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 0
#include <unistd.h>

typedef int     t_bool;

#endif FT_BOOLEAN_H
