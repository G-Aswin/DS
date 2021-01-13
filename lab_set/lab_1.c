// Design, Develop and Implement a menu driven Program in C for the following array
// operations.
// a. Creating an array of N Integer Elements
// b. Display of array Elements with Suitable Headings
// c. Inserting an Element (ELEM) at a given valid Position (POS)
// d. Deleting an Element at a given valid Position (POS)
// e. Exit.
// Support the program with functions for each of the above operations.

#include <stdio.h>

void fill_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Idx %d", i);
        scanf("%d", &a[i]);
    }
}

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

int delete_position(int *a, int n, int pos)
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

void display_array(int *a, int n)
{
    printf("The array contains : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}



int main()
{
    int n = 0, ch, pos, item;
    int arr[50];
    while(1)
    {
        printf("\n1. Create an array\n2. Display the array\n");
        printf("3. Insert an element at a position\n");
        printf("4. Delete an element from a position\nAnything else: exit\n");
        printf("Choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter the number of elements (max50) : ");
                    scanf("%d", &n);
                    fill_array(arr, n);
                    break;

            case 2: display_array(arr, n);
                    break;

            case 3: printf("Enter the element to insert and position: ");
                    scanf("%d, %d", &item, &pos);
                    n = insert_position(arr, n, item, pos);
                    break;

            case 4: printf("Enter the position to be deleted : ");
                    scanf("%d", &pos);
                    n = delete_position(arr, n, pos);
                    break;

            default: return;
        }
    }
}