#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct emp
{
    int eid;
    char name[20];
    float sal;
} E;

E* accept(E *t, int *n)
{
    printf("\n Enter Number of elements : ");
    scanf("%d", n);

    t = (E *) realloc(t, sizeof(E)*(*n));

    printf("Enter the ele of the struct\n");
    
    for (int i = 0; i < *n; i++)
    {
        printf("\nStruct %d:\n", i + 1);
        scanf("%d%s%f", &(t[i].eid), t[i].name, &(t[i].sal));
    }

    return t;
}


void display(E *t, int n)
{
    printf("\nElements of the struct are \n");
    for (int i = 0; i < n; i++)
    {
    printf("Eid = %d, Ename = %s, Esal = %f",
    t[i].eid, t[i].name, t[i].sal);
    printf("\n");

    }
    
}

void insert_into(E *a, int *n)
{
    int p;
    E new;
    printf("\nEnter the eid : ");
    scanf("%d", &new.eid);
    printf("\nEnter the name : ");
    scanf("%s", new.name);
    printf("\nEnter the sal : ");
    scanf("%f", &new.sal);

    printf("\nEnter destination index for ele : ");
    scanf("%d", &p);

    if (p < 0 || p > *n)
    {
        printf("\nInvalid IDX!\n");
        return;
    }

    *n = *n + 1;
    a = (E *)realloc(a, sizeof(E)*(*n));

    if (p == *n - 1)
    {
        a[p] = new;
        return;
    }
    
    for (int i = *n - 1; i > p; i--)
    {
        a[i] = a[i - 1];
    }

    a[p] = new;
    return; 
}

void delete_from(E *a, int *n)
{
    char target[20];
    int pos = -1;
    printf("\nEnter the name to delete:");
    scanf("%s", target);

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(a[i].name, target) == 0)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("\nName Not found!");
        return;
    }

    for (int i = pos; i < *n - 1; i++)
    {
        a[pos] = a[pos + 1];
    }

    *n = *n - 1;

    a = (E *)realloc(a, sizeof(E)*(*n));
}

int main()
{
    E *p;
    p = (E *) malloc(sizeof(E)*1);
    int n = 0, choice = -1;

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