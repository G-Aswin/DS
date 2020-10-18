#include <stdio.h>

typedef struct sparse
{
    int row;
    int col;
    int val;
} S;

void copy_struct_array(S temp[], S sparse[])
{
    for (int i = 0; i <= sparse[0].val; i++)
    {
        temp[i].row = sparse[i].row;
        temp[i].col = sparse[i].col;
        temp[i].val = sparse[i].val;
    }
}

void accept(S sparse[])
{
    int n, m, k = 1, ele;

    printf("\nEnter the array elements");
    printf("\nEnter the number of rows : ");
    scanf("%d", &n);
    printf("\nEnter the number of colums : ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("\nEnter ele at (%d,%d) : ", i, j);
            scanf("%d", &ele);

            if (ele != 0)
            {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = ele;
                k++;
            }
        }
    }

    sparse[0].row = n;
    sparse[0].col = m;
    sparse[0].val = k - 1;

}

void transpose(S sparse[])
{
    S temp[20];

    // Copies the contents of sparse into temp
    copy_struct_array(temp, sparse);

    // Swapping the value of row and col for resultant sparse matrix
    int t = sparse[0].row;
    sparse[0].row = sparse[0].col;
    sparse[0].col = t;

    int k = 1;

    for (int i = 0; i < sparse[0].row; i++)
    {
        for (int j = 1; j <= temp[0].val; j++)
        {
            if (temp[j].col == i)
            {
                sparse[k].col = temp[j].row;
                sparse[k].row = temp[j].col;
                sparse[k].val = temp[j].val;
                k++;
            }
        }
    }
}

void display(S sparse[])
{
    printf("\nThe sparse matrix looks like : \n");
    for (int i = 1; i <= sparse[0].val; i++)
    {
        printf("Element at [%d,%d] is %d.\n", sparse[i].row, sparse[i].col, sparse[i].val);
    }
}

void display_as_array(S sparse[])
{
    int k = 1;
    for (int i = 0; i < sparse[0].row; i++)
    {
        for (int j = 0; j < sparse[0].col; j++)
        {
            if (k <= sparse[0].val && 
               i == sparse[k].row &&
               j == sparse[k].col)
            {
                printf("%d\t", sparse[k].val);
                k++;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main()
{
    S sparse[20];

    accept(sparse);
    display(sparse);
    display_as_array(sparse);
    transpose(sparse);
    printf("\n*******************\n");
    display_as_array(sparse);

    return 0;
}