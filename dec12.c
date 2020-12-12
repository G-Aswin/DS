// Circular SLL with the header pointer(first)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode();
void insert_into_front(NODE head, int x);
void insert_into_rear(NODE head, int x);
void delete_from_front(NODE head);
void delete_from_rear(NODE head);
void display(NODE head);

int main()
{
    NODE head = getnode();
    head->link = head;
    int ch, x;

    while (1)
    {
        printf("\n1. Insert into front");
        printf("\n2. Insert into rear");
        printf("\n3. Delete from front");
        printf("\n4. Delete from rear");
        printf("\n5. Display\n\nEnter your choice :");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: printf("Enter a number to insert : ");
                    scanf("%d", &x);
                    insert_into_front(head, x);
                    break;
            case 2: printf("Enter a number to insert : ");
                    scanf("%d", &x);
                    insert_into_rear(head, x);
                    break;
            case 3: delete_from_front(head);    break;
            case 4: delete_from_rear(head);     break;
            case 5: display(head);              break;

            default: return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
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

void insert_into_front(NODE head, int x)
{
    NODE node = getnode();
    node->info = x;

    node->link = head->link;
    head->link = node;
    return;
}

void insert_into_rear(NODE head, int x)
{
    NODE node = getnode();
    node->info = x;

    NODE curr = head->link;
    while(curr->link != head)
        curr = curr->link;
    node->link = head;
    curr->link = node;
}

void delete_from_front(NODE head)
{
    //No elements
    if (head->link == head)
    {
        printf("Nothing to delete\n");
        return;
    }

    NODE node = head->link;
    head->link = node->link;
    printf("We are deleting %d from the list\n", node->info);
    free(node);
}

void delete_from_rear(NODE head)
{
    //No elements
    if (head->link == head)
    {
        printf("Nothing to delete\n");
        return;
    }

    NODE curr = head->link;
    while(curr->link->link != head)
        curr = curr->link;

    NODE node = curr->link;
    curr->link = node->link;
    printf("We are deleting %d from the list\n", node->info);
    free(node);
    return;
}

void display(NODE head)
{
    if (head->link == head)
    {
        printf("There are no elements to delete.\n");
        return;
    }
    NODE curr = head->link;
    printf("Elements of the CLL are : \n");

    while(curr != head)
    {
        printf("%d\n", curr->info);
        curr = curr->link;
    }
}