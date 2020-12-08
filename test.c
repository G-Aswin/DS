// Linked list skeleton

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    float sal;
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
    char name[20];
    float sal;
    printf("Enter the name : ");
    scanf("%s", name);
    printf("Enter sal : ");
    scanf("%f", &sal);

    NODE new = getnode();
    strcpy(new->name, name);
    new->sal = sal;

    new->link = first;
    first = new;
    return first;
}

NODE insert_into_rear(NODE first)
{
    char name[20];
    float sal;
    printf("Enter the name : ");
    scanf("%s", name);
    printf("Enter sal : ");
    scanf("%f", &sal);

    NODE new = getnode();
    strcpy(new->name, name);
    new->sal = sal;
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
    printf("The name deleted is %s\n", first->name);
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
        printf("The name deleted is %s\n", node->name);
        free(node);
        first = NULL;
        return first;
    }

    NODE curr = first;
    while (curr->link->link != NULL)
        curr = curr->link;
    NODE node = curr->link;
    printf("The name deleted is %s\n", node->name);
    curr->link = NULL;
    free(node);
    return first;
}

void search(NODE first)
{
    char name[20];
    printf("Enter the name :");
    scanf("%s", name);
    
    NODE curr = first;
    while (curr != NULL)
    {
        if (strcmp(curr->name, name) == 0)
        {
            printf("Element found!\n");
            return;
        }
        curr = curr->link;
    }
    printf("The target was not found!\n");
    return;
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
        printf("%s - %f\n", curr->name, curr->sal);
        curr = curr->link;
    }
}


int main()
{
    NODE first = NULL, second = NULL;
    int ch = 0;
    while (1)
    {
        printf("\n\n1.Insert Front\n2. Insert Rear\n3. Display\n");
        printf("4. Delete Front\n5. Delete Rear\n6. Search\n7. Exit\n");
        // printf("8. Insert into front of second\n9.Join SLL\n\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: first = insert_into_front(first);   break;
            case 2: first = insert_into_rear(first);    break;
            case 3: display(first);                     break;
            case 4: first = delete_from_front(first);   break;
            case 5: first = delete_from_rear(first);    break;
            case 6: search(first);                 break;
            case 8: second = insert_into_front(second);  break;
            case 9: first = join_sll(first, second);    break;
            default: return 0;
        }
    }
    return 0;
}