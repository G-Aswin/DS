// Double ended linear queue
// functions to include : 1. addfront 2. addrear 3. removefront 4. removerear
#include <stdio.h>
#define MAX 5

void addfront(int queue[], int *front, int *rear)
{
    int ele;
    printf("Enter the number : ");
    scanf("%d", &ele);

    if (*front == 0 && *rear == -1)
    {
        printf("This is the first element.\n");
        *rear += 1;
        queue[*rear] = ele;
    }
    else if (*front == 0)
    {
        printf("No space at front!\n");
    }
    else
    {
        *front = *front - 1;
        queue[*front] = ele;
    }
}

void addrear(int queue[], int *rear)
{
    int ele;
    printf("Enter the number : ");
    scanf("%d", &ele);

    if (*rear == MAX - 1)
    {
        printf("No space at the rear!\n");
    }
    else
    {
        *rear = *rear + 1;
        queue[*rear] = ele;
    }
}

void removefront(int queue[], int *front, int *rear)
{
    if (*front > *rear)
    {
        printf("The queue is empty!\n");
    }
    else
    {
        int ele = queue[*front];
        printf("Removing the number %d\n", ele);
        *front = *front + 1;
    }
}

void removerear(int queue[], int *front, int *rear)
{
    if (*front > *rear)
    {
        printf("The queue is empty!\n");
    }
    else
    {
        int ele = queue[*rear];
        printf("Removing the number %d\n", ele);
        *rear = *rear - 1;
    }

    if (*front > *rear)
    {
        *front = 0;
        *rear = -1;
    }
}

void display(int queue[], int front, int rear)
{
    if (front > rear)
    {
        printf("The queue is empty!\n");
        return;
    }
    printf("\nQueue\n");
    for (int i = front; i <= rear; i++)
        printf("%d\n", queue[i]);
    printf("\n");
}

int main()
{
    int queue[MAX], front = 0, rear = - 1, ch;
    while (1)
    {
        printf("\n\n1.PushFront\n2.PushBack\n3.RemoveFront\n4.RemoveRear\n5.Display\nAnything else-> Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: addfront(queue, &front, &rear);
                    break;
            case 2: addrear(queue, &rear);
                    break;
            case 3: removefront(queue, &front, &rear);
                    break;
            case 4: removerear(queue, &front, &rear);
                    break;
            case 5: display(queue, front, rear);
                    break;
            default: return 0;
        }
    }

    return 0;
}