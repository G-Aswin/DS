// Circular queue program
#include <stdio.h>
#define MAX 5

void enqueue(int queue[], int *rear, int *count)
{
    if (*count == MAX)
    {
        printf("The queue is full!\n");
        return;
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
    int queue[MAX], front = 0, rear = MAX - 1, count = 0, ch;
    while (1)
    {
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\nAnything else-> Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: enqueue(queue, &rear, &count);
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