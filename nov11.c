#include <stdio.h>

// Multiple queue program
#define MAXSIZE 12
#define NoOfQueue 3

void enqueue(int queue[], int front[], int rear[], int bounds[], int i)
{
    if (rear[i] == bounds[i  + 1])
    {
        printf("The selected queue if full!\n");
        return;
    }

    int ele;
    printf("Enter the number : ");
    scanf("%d", &ele);

    rear[i]++;
    queue[rear[i]] = ele;
}

int dequeue(int queue[], int front[], int rear[], int bounds[], int i)
{
    if (front[i] > rear[i])
    {
        printf("The selected queue is empty!\n");
        return -1;
    }

    int ele = queue[front[i]];
    front[i]++;
    return ele;
}

void display(int queue[], int front[], int rear[], int bounds[])
{
    for (int i = 0; i < NoOfQueue; i++)
    {
        printf("Queue number : %d\n", i);

        if (front[i] > rear[i])
        {
            printf("Empty\n");
            continue;
        }
        
        for (int j = front[i]; j <= rear[i]; j++)
        {
            printf("%d\n", queue[j]);
        }
    }
}

int main()
{
    int queue[MAXSIZE], bounds[NoOfQueue + 1], front[NoOfQueue + 1], rear[NoOfQueue + 1], ch, x;
    for (int i = 0; i <= NoOfQueue; i++)
    {
        rear[i] = bounds[i] = (MAXSIZE/NoOfQueue)*i - 1;
        front[i] = rear[i] + 1;
    }
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter your queue number : ");
            scanf("%d", &x);
            if (x < 0 || x >= NoOfQueue)
            {
                printf("Invalid queue Number\n");
                continue;
            }
            enqueue(queue, front, rear, bounds, x);
            break;
        case 2:
            printf("Enter your stack number : ");
            scanf("%d", &x);
            if (x < 0 || x >= NoOfQueue)
            {
                printf("Invalid Stack Number\n");
                continue;
            }
            dequeue(queue, front, rear, bounds, x);
            break;
        case 3:
            display(queue, front, rear, bounds);
            break;
        
        default:
            return 0;
        }
    }
}