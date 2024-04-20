#include <stdio.h>

int main (int argc, char const *argv[])
{
    int var = 10;

printf("Dia chi var: %p\n", &var);

    int *ptr = &var;

printf("Dia chi con tro ptr: %p\nGiá trị con trỏ ptr: %d\n", ptr, *ptr);
    return 0;
}