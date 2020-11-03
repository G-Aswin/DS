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
        printf("Term %d : ", i+1);
        scanf("%d %d", &p[i].coeff, &p[i].exp);
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

void add_polynomials(P *p1, int *n, P *p2, int *m)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            if (p1[i].exp == p2[j].exp)
            {
                p1[i].coeff += p2[j].coeff;
                p2[j].coeff = -999;
            }
        }
    }
    int x = *n;
    for (int j = 0; j < *m; j++)
    {
        if (p2[j].coeff != -999)
        {
            p1[x].coeff = p2[j].coeff;
            p1[x].exp = p2[j].exp;
            x++;
        }
    }
    *n = x;
}


int main()
{
    int n, m;
    printf("\nEnter lengths of p1 and p2 : ");
    scanf("%d %d", &n, &m);

    P p1[20], p2[20];
    accept(p1, n);
    accept(p2, m);

    add_polynomials(p1, &n, p2, &m);
    display(p1, n);
}