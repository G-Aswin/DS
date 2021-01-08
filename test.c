#include <stdio.h>


int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n*factorial(n - 1);
}

int main()
{
    int t, x;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &x);
        printf("%d\n", factorial(x));
    }
}

