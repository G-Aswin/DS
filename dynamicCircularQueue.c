// Dynamic Circular queue program
#include <stdio.h>
#include <stdlib.h>

int MAX = 2;

void enqueue(int queue[], int *front, int *rear, int *count)
{
    if (*count == MAX)
    {
        printf("The queue is full! Time for some Dynamic Action ;)\n");
        queue = (int *)realloc(queue, sizeof(int)*MAX*2); // Doubles the size each time it hits the limit.
        
        if (*front > *rear)
        {
            int curr = MAX - 1;
            while (curr != (*front - 1)%MAX)
            {
                queue[curr + MAX] = queue[curr];
                curr--;
            }
            *front = (*front + MAX);
        }
        MAX *= 2;
    }
    int ele;
    printf("Enter the element to be inserted : ");
    scanf("%d", &ele);

    *rear = (*rear + 1) % MAX;
    queue[*rear] = ele;
    *count = *count + 1;
}

void dequeue(int queue[], int *front, int *count)
{
    if (*count == 0)
    {
        printf("The queue is empty !\n");
        return;
    }
    int ele = queue[*front];
    *front = (*front + 1) % MAX;
    *count = *count - 1;

    printf("The dequeued number is %d\n", ele);
}

void display(int queue[], int front, int count)
{
    printf("The queue is ->\n");
    for (int _ = 0; _ < count; _++)
    {
        printf("%d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}


int main()
{
    int *queue, front = 0, rear = MAX - 1, count = 0, ch;
    queue = (int *)malloc(sizeof(int)*MAX);
    while (1)
    {
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\nAnything else-> Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: enqueue(queue, &front, &rear, &count);
                    break;
            case 2: dequeue(queue, &front, &count);
                    break;
            case 3: display(queue, front, count);
                    break;
            default: return 0;
        }
    }

    return 0;
}