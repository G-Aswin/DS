// Linked list skeleton

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode();
NODE insert_into_front_direct(NODE first, int x);
// NODE insert_into_rear_direct(NODE first, int x);
// NODE insert_into_front(NODE first);
// NODE insert_into_rear(NODE first);
NODE delete_from_front(NODE first);
// NODE delete_from_rear(NODE first);
// void search(NODE first);
int length_sll(NODE first);
NODE insert_at(NODE first);
NODE delete_at(NODE first);
void display(NODE first);


int main()
{
    NODE first = NULL, second = NULL;
    int ch = 0;
    while (1)
    {
        printf("\n\n1.Insert@IDX\n2Delete@IDX\n3. Display\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: first = insert_at(first);           break;
            case 2: first = delete_at(first);           break;
            case 3: display(first);    					break;
            default: return 0;
        }
    }
    return 0;
}

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

NODE insert_into_front_direct(NODE first, int x)
{
    NODE new = getnode();
    new->info = x;
    new->link = first;
    first = new;
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

int length_sll(NODE first)
{
    int size = 0;
    NODE curr = first;
    while(curr != NULL)
    {
        size++;
        curr = curr->link;
    }
    return size;
}

NODE insert_at(NODE first)
{
    int x, idx;
    printf("Enter the value and location respectively : ");
    scanf("%d %d", &x, &idx);

    int n = length_sll(first);
    if (idx < 0 || idx > n)
    {
        printf("Invalid IDX!\n");
        return first;
    }

    NODE node = getnode();
    node->info = x;
    node->link = NULL;

    if (idx == 0)
        return insert_into_front_direct(first, x);
    else
    {
        NODE curr = first;
        while (--idx)
            curr = curr->link;
        node->link = curr->link;
        curr->link = node;
    }
    return first;
}

NODE delete_at(NODE first)
{
    int idx;
    printf("Enter the location respectively : ");
    scanf("%d", &idx);

    int n = length_sll(first);
    if (idx < 0 || idx >= n)
    {
        printf("Invalid IDX!\n");
        return first;
    }

    if (idx == 0)
        return delete_from_front(first);
    
    NODE curr = first;
    while (--idx)
        curr = curr->link;

    NODE node = curr->link;
    curr->link = node->link;
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