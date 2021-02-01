//DFS
#include <stdio.h>

//graph and flags declared globally
int graph[10][10], flag[10];

void read_graph(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nIs there a node from %d to %d ? (1/0) : ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
}


void dfs(int u, int n)
{
    flag[u] = 1;
    printf("%d ", u);

    for (int i = 0; i < n; i++)
        if (graph[u][i] == 1 && flag[i] == 0)
            dfs(i,n);
}

void dfs_iter(int u, int n)
{
    int top = -1, stack[10];
    stack[++top] = u;

    while (top != -1)
    {
        u = stack[top--];
        if (flag[u] == 0)
        {
            printf("%d ", u);
            flag[u] = 1;
        }
        for (int v = n - 1; v >= 0; v--)
        {
            if (graph[u][v] == 1 && flag[v] == 0)
                stack[++top] = v;
        }
    }
}

void bfs_iter(int u, int n)
{
    int front = 0, rear = -1, queue[20];
    printf("%d ", u);
    queue[++rear] = u;
    flag[u] = 1;

    while(front <= rear)
    {
        u = queue[front++];
        for (int v = 0; v < n; v++)
            if (graph[u][v] == 1 && flag[v] == 0)
            {
                printf("%d ", v);
                flag[v] = 1;
                queue[++rear] = v;
            }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes in this graph : ");
    scanf("%d", &n);

    read_graph(n);

    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < n; x++)
            flag[x] = 0;
        printf("\nThe nodes reacheable from %d is (recursive) : ", i);
        dfs(i, n);

        for (int x = 0; x < n; x++)
            flag[x] = 0;
        printf("\nThe nodes reacheable from %d is (iterative) : ", i);
        dfs_iter(i, n);

        for (int x = 0; x < n; x++)
            flag[x] = 0;
        printf("\nThe nodes reachable from %d BFS iterative : ", i);
        bfs_iter(i, n);
    }
}