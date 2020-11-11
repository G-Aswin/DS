#include<stdio.h>

void towerofhanoi(int n, char s, char t, char d)
{
    if (n == 0)
        return;
    towerofhanoi(n - 1, s, d, t);
    // move n - 1 discs from the source to temp
    printf("Move disc %d from %c to %c\n", n, s, d);
    // move n disc from source to destination
    towerofhanoi(n - 1, t, s, d);
    // move n - 1 discs from temp to destination
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n*factorial(n - 1);
}

int main()
{
    int n;
    printf("\nEnter number of discs : ");
    scanf("%d", &n);
    towerofhanoi(n, 'A', 'B', 'C');
    // printf("Factorial of %d is %d.\n", n, factorial(n));
}