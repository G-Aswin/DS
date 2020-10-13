#include <stdio.h>
#include <stdlib.h>

// void accept(int a[], int n)
// {
//     printf("\nEnter the elements : ");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
// }

// void display(int a[], int n)
// {
//     printf("\nThe array elements are : ");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", a[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int *p;
//     p = (int*) malloc(sizeof(int) * 10);
//     accept(p, 3);
//     display(p, 3);

//     return EXIT_SUCCESS;
// }


// Struct

struct emp
{
    int eid;
    char name[20];
    float sal;
};

void accept(struct emp *t, int n)
{
    int i;
    printf("Enter the ele of the struct\n");
    
    for (i = 0; i < n; i++)
    {
        printf("\nStruct %d:\n", i + 1);
        scanf("%d%s%f", &(t[i].eid), t[i].name, &(t[i].sal));
    }
}


void display(struct emp *t, int n)
{
    printf("\nElements of the struct are \n");
    for (int i = 0; i < n; i++)
    {
    printf("Eid = %d, Ename = %s, Esal = %f",
    t[i].eid, t[i].name, t[i].sal);
    printf("\n");

    }
}

// int main()
// {
//     struct emp *e1;
//     e1 = (struct emp*) malloc(sizeof(struct emp) * 3);
//     accept(e1, 3);
//     display(e1, 3);
// }


// int main()
// {
//     int *p;
//     p = (int *) calloc(5, sizeof(int));
//     // p = (int*) malloc(sizeof(int) * 5);


//     accept(p, 5);
//     display(p, 5);
// }

int main()
{
    struct emp *e1;
    
    e1 = (struct emp*) calloc(5, sizeof(struct emp*));
    accept(e1, 3);
    display(e1, 3);

    // e1 = (struct emp*) realloc(e1, sizeof(struct emp*)*2);

    // display(e1, 2);
    
}