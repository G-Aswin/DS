#include <stdio.h>

typedef struct sparse
{
    int row;
    int col;
    int val;
} S;

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

void display(S sparse[])
{
    printf("\nThe sparse matrix looks like : ");
    for (int i = 1; i <= sparse[0].val; i++)
    {
        printf("\nElement at [%d,%d] is %d.", sparse[i].row, sparse[i].col, sparse[i].val);
    }
}

int main()
{
    S sparse[20];

    accept(sparse);

    return 0;
}