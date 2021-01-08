// Circular SLL with the tail pointer(last)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode();
NODE insert_into_front(NODE last, int x);
NODE insert_into_rear(NODE last, int x);
NODE delete_from_front(NODE last);
NODE delete_from_rear(NODE last);
void display(NODE last);

int main()
{
    NODE last = NULL;
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
                    last = insert_into_front(last, x);
                    break;
            case 2: printf("Enter a number to insert : ");
                    scanf("%d", &x);
                    last = insert_into_rear(last, x);
                    break;
            case 3: delete_from_front(last);    break;
            case 4: delete_from_rear(last);     break;
            case 5: display(last);              break;

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

NODE insert_into_front(NODE last, int x)
{
    NODE node = getnode();
    node->info = x;

    //Case 1: Empty SLL
    if (last == NULL)
    {
        node->link = node;
        last = node;
        return last;
    }

    //Case 2: 1 or more elements
    node->link = last->link;
    last->link = node;
    return last;
}

NODE insert_into_rear(NODE last, int x)
{
    last = insert_into_front(last, x);
    last = last->link;
    return last;
}

NODE delete_from_front(NODE last)
{
    //No elements
    if (last == NULL)
    {
        printf("Nothing to delete\n");
        return last;
    }
    //One element only
    else if (last->link = last)
    {
        NODE node = last;
        printf("We are deleting %d from the list\n", node->info);
        free(node);
        last = NULL;
        return last;
    } 
    NODE node = last->link;
    last->link = node->link;
    printf("We are deleting %d from the list\n", node->info);
    free(node);
    return last;
}

NODE delete_from_rear(NODE last)
{
    //No elements
    if (last == NULL)
    {
        printf("Nothing to delete\n");
        return last;
    }
    //One element only
    else if (last->link = last)
    {
        NODE node = last;
        printf("We are deleting %d from the list\n", node->info);
        free(node);
        last = NULL;
        return last;
    } 
    NODE curr = last->link;
    while(curr->link != last)
        curr = curr->link;

    NODE node = last;
    curr->link = last->link;
    last = curr;
    printf("We are deleting %d from the list\n", node->info);
    free(node);
    return last;
}

void display(NODE last)
{
    if (last == NULL)
    {
        printf("There are no elements to delete.\n");
        return;
    }
    NODE curr = last->link;
    printf("Elements of the CLL are : \n");

    while(curr != last)
    {
        printf("%d\n", curr->info);
        curr = curr->link;
    }
    printf("%d\n\n", curr->info);
}

NODE concatenate(NODE last1, NODE last2)
{
    NODE curr = last1->link;

    while(curr != last1)
    {
        last2 = insert_into_rear(last2, curr->info);
        curr = curr->link;
    }
    last2 = insert_into_rear(last2, curr->info);
    return last2;
}