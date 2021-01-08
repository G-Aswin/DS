// Doubly Linked List Skeleton

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};
typedef struct node * NODE;

NODE getnode()
{
    NODE x = (NODE) malloc(sizeof(struct node));
    if (x == NULL)
        exit(0);
    return x;
}

NODE insert_front(NODE first, int x)
{
    NODE new = getnode();
    new->info = x;
    new->left = NULL;

    if (first == NULL)
    {
        new->right = NULL;
        first = new;
        return first;
    }

    new->right = first;
    first->left = new;
    first = new;
    return first;
}

NODE insert_rear(NODE first, int x)
{
    NODE new = getnode();
    new->info = x;
    new->right = NULL;

    if (first == NULL)
    {
        new->left = NULL;
        first = new;
        return first;
    }

    NODE curr = first;
    while (curr->right != NULL)
        curr = curr->right;

    curr->right = new;
    new->left = curr;
    return first;
}

NODE delete_front(NODE first)
{
    if (first == NULL)
    {
        printf("Nothing to delete.\n");
        return first;
    }
    NODE node = first;
    first = first->right;

    //Handles single element DLL
    if (first != NULL)
        first->left = NULL;

    printf("Deleting node with info %d.\n", node->info);
    free(node);
    return first;
}

NODE delete_rear(NODE first)
{
    if (first == NULL)
    {
        printf("Nothing to delete.\n");
        return first;
    }
    else if (first->right == NULL) // only one node
    {
        NODE node = first;
        first = NULL;
        printf("Deleting node with info %d.", node->info);
        free(node);
        return first;
    }
    NODE curr = first;
    while(curr->right->right != NULL)
        curr = curr->right;
    
    NODE node = curr->right;
    curr->right = NULL;
    printf("Deleting node with info %d.", node->info);
    free(node);
    return first;
}

void display(NODE first)
{
    if (first == NULL)
    {
        printf("Nothing to display.\n");
        return;
    }

    NODE curr = first;
    while(curr != NULL)
    {
        printf("%d\n", curr->info);
        curr = curr->right;
    }
}


int main()
{
    NODE first = NULL;
    int x, ch;

    while(1)
    {
        printf("\n1.Insert Front");
        printf("\n2.Insert Rear");
        printf("\n3.Delete Front");
        printf("\n4.Delete Rear");
        printf("\n5.Display");
        printf("\n\nChoice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter the item to insert : ");
                    scanf("%d", &x);
                    first = insert_front(first, x);
                    break;

            case 2: printf("Enter the item to insert : ");
                    scanf("%d", &x);
                    first = insert_rear(first, x);
                    break;
            
            case 3: first = delete_front(first);    break;
            case 4: first = delete_rear(first);     break;
            case 5: display(first);                 break;

            default: return 0;
        }
    }
}