#include <stdio.h>
#include <stdlib.h>

int * accept(int *a, int *n)
{
    printf("\nEnter the number of elements: ");
    scanf("%d", n);

    a = (int*) malloc(sizeof(int)*(*n));

    printf("\nEnter the total elements : ");

    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &a[i]);
    }

    return a;
}

void display(int *a, int n)
{
    printf("\nThe total elements : ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}


void insert_into(int *a, int *n)
{
    int ele, p;
    printf("\nEnter the element to insert : ");
    scanf("%d", &ele);
    printf("\nEnter destination index for ele : ");
    scanf("%d", &p);

    if (p < 0 || p > *n)
    {
        printf("\nInvalid IDX!\n");
        return;
    }

    *n = *n + 1;
    a = (int *)realloc(a, sizeof(int)*(*n));

    if (p == *n - 1)
    {
        a[p] = ele;
        return;
    }

    // [1, 2, 3, 4, 5]
    
    for (int i = *n - 1; i > p; i--)
    {
        a[i] = a[i - 1];
    }

    a[p] = ele;
    return; 
}


void delete_from(int *a, int *n)
{
    int pos;
    printf("\nEnter the position to delete:");
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n)
    {
        printf("\nInvalid Pos!");
        return;
    }

    for (int i = pos; i < *n - 1; i++)
    {
        a[pos] = a[pos + 1];
    }

    *n = *n - 1;

    a = realloc(a, sizeof(int)*(*n));
}




int main()
{
    int *p, n = 0, choice = -1;

    do
    {
        printf("\n1.Create\n2.Insert@\n3.Delete@\n4.Display\n5.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            p = accept(p, &n);
            break;
        case 2:
            insert_into(p, &n);
            break;
        case 3:
            delete_from(p, &n);
            break;
        case 4:
            display(p, n);
            break;
        default:
            return 0;
        }
        
    } while (choice != 5);
    
    return 0;
}