// Dynamic Linear Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int *enqueue(int queue[], int *front, int *rear)
{
    int ele;

    if (*rear >= MAX - 1)
    {
        queue = (int *)realloc(queue, sizeof(*rear + 2));
    }

    printf("\nEnter the Number : ");
    scanf("%d", &ele);

    *rear = *rear + 1;
    queue[*rear] = ele;
    return queue;
}

int *dequeue(int queue[], int *front, int *rear)
{
    if (*front > *rear)
    {
        printf("\nQueue is empty\n");
        return queue;
    }

    int ele = queue[*front];
    printf("\nDequeuing %d\n", ele);
    *front = *front + 1;
    queue = (int *)realloc(queue, sizeof(*rear) - 1);

    return queue;
}

void display(int queue[], int *front, int *rear)
{
    if (*front > *rear)
    {
        printf("\nQueue is empty\n");
        return;
    }
    for (int i = *front; i <= *rear; i++)
    {
        printf("\n%d", queue[i]);
    }
    printf("\n");
}


int main()
{
    int ch, front = 0, rear = -1;
    int *queue = (int *)calloc(MAX, sizeof(int));
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue(queue, &front, &rear);
            break;
        case 2:
            dequeue(queue, &front, &rear);
            break;
        case 3:
            display(queue, &front, &rear);
            break;
        
        default:
            return 0;
        }
    }
}