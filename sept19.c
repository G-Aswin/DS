#include<stdio.h>

int delete_pos(int *a, int n, int pos)
{

    if (pos < 0 || pos > n - 1){
        return n;
    }

    int start = pos, end = n;

    while (start < end - 1){
        a[start] = a[start + 1];
        start++;
    }

    return --n;;
}


void display(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
}

int main()
{
    int a[20] = {11, 22, 33, 44, 55};
    int n = 5;
    int pos = 2;

    display(a, n);
    n = delete_pos(a, n, pos);
    printf("\nDeletion done\n");
    display(a, n);
}