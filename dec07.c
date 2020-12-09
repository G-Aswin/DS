// Joining Two Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode();
NODE insert_into_front(NODE first);
NODE insert_into_rear(NODE first);
NODE delete_from_front(NODE first);
NODE delete_from_rear(NODE first);
NODE join_sll(NODE first, NODE second);
void display(NODE first);

int main()
{
    NODE first = NULL, second = NULL;
    int ch = 0;

    printf("Inserting the First SLL\n");
    while(ch != 6)
    {
        printf("\n1.Insert Front");
        printf("\n2.Insert Rear");
        printf("\n3.Delete Front");
        printf("\n4.Delete Rear");
        printf("\n5.Display");
        printf("\n6. Exit Loop");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: first = insert_into_front(first);   break;
            case 2: first = insert_into_rear(first);    break;
            case 3: first = delete_from_front(first);   break;
            case 4: first = delete_from_rear(first);    break;
            case 5: display(first);                     break;
            default: break;
        }
    }

    ch = 0;
    printf("Inserting the Second SLL\n");
    while(ch != 6)
    {
        printf("\n1.Insert Front");
        printf("\n2.Insert Rear");
        printf("\n3.Delete Front");
        printf("\n4.Delete Rear");
        printf("\n5.Display");
        printf("\n6. Exit Loop");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: second = insert_into_front(second);   break;
            case 2: second = insert_into_rear(second);    break;
            case 3: second = delete_from_front(second);   break;
            case 4: second = delete_from_rear(second);    break;
            case 5: display(second);                     break;
            default: break;
        }
    }

    printf("\nJoining the two SLL\n:");
    first = join_sll(first, second);

    printf("\nThe new SLL is \n");
    display(first);
    return 0;
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

NODE join_sll(NODE first, NODE second)
{
    if (first == NULL)
    {
        first = second;
        return first;
    }
    NODE curr = first;
    while(curr->link != NULL)
        curr = curr->link;
    curr->link = second;
    return first;
}