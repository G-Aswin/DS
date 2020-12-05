// Linked list skeleton

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

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


NODE insert_into_front(NODE first)
{
    int x;
    printf("Enter the number to be inserted : ");
    scanf("%d", &x);

    NODE new = getnode();
    new->info = x;
    new->link = first;
    first = new;
    return first;
}

NODE insert_into_rear(NODE first)
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

    return first;
}

NODE delete_from_front(NODE first)
{
    if (first == NULL)
    {
        printf("The SLL is empty!\n");
        return first;
    }
    printf("The value deleted is %d\n", first->info);
    NODE node = first;
    first = first->link;
    free(node);
    return first;
}

NODE delete_from_rear(NODE first)
{
    if (first == NULL)
    {
        printf("The SLL is empty!\n");
        return first;
    }

    if (first->link == NULL)
    {
        NODE node = first;
        printf("The value deleted is %d\n", node->info);
        free(node);
        first = NULL;
        return first;
    }

    NODE curr = first;
    while (curr->link->link != NULL)
        curr = curr->link;
    NODE node = curr->link;
    printf("The value deleted is %d\n", node->info);
    curr->link = NULL;
    free(node);
    return first;
}

void search(NODE first, int key)
{
    NODE curr = first;
    while (curr != NULL)
    {
        if (curr->info == key)
        {
            printf("Element found!\n");
            return;
        }
        curr = curr->link;
    }
    printf("The target was not found!\n");
    return;
}

void display(NODE first)
{
    if (first == NULL)
    {
        printf("The LL is empty!\n");
        return;
    }
    printf("The LL is : \n");
    NODE curr = first;
    while (curr != NULL)
    {
        printf("%d\n", curr->info);
        curr = curr->link;
    }
}


int main()
{
    NODE first = NULL;
    int ch = 0, key;
    while (1)
    {
        printf("1.Insert Front\n2. Insert Rear\n3. Display\n");
        printf("4. Delete Front\n5.Delete Rear\n6.Search\n7.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: first = insert_into_front(first);   break;
            case 2: first = insert_into_rear(first);    break;
            case 3: display(first);     break;
            case 4: first = delete_from_front(first);   break;
            case 5: first = delete_from_rear(first);    break;
            case 6: printf("Enter the key :");
                    scanf("%d", &key);
                    search(first, key);
                    break;
            default: return 0;
        }
    }
    return 0;
}