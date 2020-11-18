#include<stdio.h>


int insert_position(int *a, int n, int ele, int pos)
{
    int start = n, target = pos;

    if (pos < 0 || pos >= n)
    {
        printf("Out of bounds");
        return -1;
    }

    while (start != target)
    {
        a[start] = a[start - 1];
        start--;
    }

    a[target] = ele;
    n++;

    return n;
}

void printarray(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}



int main()
{
    int ele, pos;
    int a[20] = {11, 22, 33, 55, 66, 77};
    int n = 6;

    printarray(a, n);

    printf("\nEnter the value to be inserted : ");
    scanf("%d", &ele);

    printf("\nEnter the position to be inserted in : ");
    scanf("%d", &pos);

    n = insert_position(a, n, ele, pos);

    printarray(a, n);

    return 0;
}