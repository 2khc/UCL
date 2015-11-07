#include <stdio.h>
#include <limits.h>
#include <string.h.

int* sort(int* n);
int * intdup(int const * src, size_t len);

int main(void)
{
    int *n = (int[11])
    {
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };

    sort(n);
}

int* sort(int *n)
{
    int len;
    do
    {
        len++;
    }
    while (*n++);

   int *copy = intdup(n, len);

}

int * intdup(int const * src, size_t len)
{
    int * p = malloc(int const * sizeof(int));
    memcpy(p,src,len*sizeof(int));
    return p;
}
