// Header SLL

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode();
void insert_into_front(NODE first);
void insert_into_rear(NODE first);
void delete_from_front(NODE first);
void delete_from_rear(NODE first);
void display(NODE first);

int main()
{
    NODE head = getnode();
    head->link = NULL;
    int ch = 0;

     while (1)
    {
        printf("\n\n1.Insert Front\n2. Insert Rear\n3. Display\n");
        printf("4. Delete Front\n5. Delete Rear\nAnything else: Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert_into_front(head);   break;
            case 2: insert_into_rear(head);    break;
            case 3: display(head);                     break;
            case 4: delete_from_front(head);   break;
            case 5: delete_from_rear(head);    break;
            default: return 0;
        }
    }


}

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
    new->link = first->link;
    first->link = new;
}

void insert_into_rear(NODE first)
{
    int x;
    printf("Enter the number to be inserted : ");
    scanf("%d", &x);

    NODE new = getnode();
    new->info = x;
    new->link = NULL;
    NODE curr = first->link;

    if (curr == NULL) //empty SLL
        first->link = new;
    else
    {
        while(curr->link != NULL)
            curr = curr->link;
        curr->link = new;
    }
}

void delete_from_front(NODE first)
{
    if (first->link == NULL)
    {
        printf("The SLL is empty!\n");
        return;
    }
    printf("The value deleted is %d\n", first->link->info);
    NODE node = first->link;
    first->link = node->link;
    free(node);
}

void delete_from_rear(NODE first)
{
    if (first->link == NULL)
    {
        printf("The SLL is empty!\n");
        return;
    }

    if (first->link->link == NULL)
    {
        NODE node = first->link;
        printf("The value deleted is %d\n", node->info);
        free(node);
        first->link = NULL;
        return;
    }

    NODE curr = first->link;
    while (curr->link->link != NULL)
        curr = curr->link;
    NODE node = curr->link;
    printf("The value deleted is %d\n", node->info);
    curr->link = NULL;
    free(node);
}

void display(NODE first)
{
    if (first->link == NULL)
    {
        printf("The LL is empty!\n");
        return;
    }
    printf("The LL is : \n");
    NODE curr = first->link;
    while (curr != NULL)
    {
        printf("%d\n", curr->info);
        curr = curr->link;
    }
}