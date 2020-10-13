#include<stdio.h>

typedef struct polynomial{
    int coeff;
    int exp;
}P;

void accept(P *p, int n)
{
    printf("\nEnter the coeff, then exponent : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Term %d", i+1);
        scanf("%d %d", p[i].coeff, p[i].exp);
    }
    printf("\n");

}

void display(P *p, int n)
{
    printf("\nThe polynomial is : ");
    for (int i = 0; i < n; i++)
    {
        if (p[i].coeff >= 0)
            printf("+%dx^%d ", p[i].coeff, p[i].exp);
        else
            printf("%dx^%d ", p[i].coeff, p[i].exp);
    }
    printf("\n");
}

void add_polynomials(P *p1, int n, P *p2, int m)
{
    // Iterate over p1
        //Iterate over p2
            //check if powers of p1 and p2 match
            //if they do, add coeff and save new struct
        // Didnt find? add p1 ele
    // Add untouched p2 elements
}