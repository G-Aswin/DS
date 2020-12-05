#include <stdio.h>

int main()
{
    static int x[] = {5, 15, 25, 35, 45, 55}; //  base address 2000
    static int **pntr = {x, x+1, x+2, x+3, x+4}; // {2000, 2004, 2008, 2012, 2016, 2020}

    int **p_pntr = pntr; // pntr x, therefor p_pntr = x
    p_pntr++; // x + 1
    printf("%d", *p_pntr-x); // x + 1 - x


    // x + 1 = x + sizeof(int)*1
    // x + 2 = x + sizeof(int)*2
}