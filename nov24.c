// Linked list skeleton

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;
NODE first; // the head pointer

//allocate memory
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("\nMemory was not allocated !");
        exit(0);
    }
    return x;
}


void insert_into_front(NODE first)
{
    int x;
    printf("Enter the number to be inserted : ");
    scanf("%d", &x);

    NODE new = getnode();
    new->info = x;
    new->link = first;
    first = new;
}

void insert_into_rear(NODE first)
{
    int x;
    printf("Enter the number to be inserted : ");
    scanf("%d", &x);

    NODE new = getnode();
    new->info = x;
    new->link = NULL;
    NODE curr = first;

    if (first == NULL) //empty SLL
        first = new;
    else
    {
        curr = first;
        while(curr->link != NULL)
            curr = curr->link;
        curr->link = new;
    }
}