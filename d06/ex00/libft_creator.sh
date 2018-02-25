#/bin/sh
gcc -c *.c
ar -cvq libft.a *.o
rm *.o
mkdir functions
mv *.c functions
