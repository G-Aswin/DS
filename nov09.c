#include <stdio.h>

int gcd(int m, int n)
{
    if (m == n)
        return m;
    else
    {
        if (m > n)
            return gcd(m - n, n);
        else
            return gcd(m, n - m);
    }
}

// function to return the fibonacci value of a particular position
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // int a, b;
    // printf("Enter the values of a and b: ");
    // scanf("%d %d", &a, &b);

    // printf("GCD of %d and %d is %d", a, b, gcd(a, b));
    // printf("fibonacci at 10 is %d\n", fibonacci(10));


    int n;
    printf("Enter num : ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
        printf("\t%d", fibonacci(i));
    return 0;
}