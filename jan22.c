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
        printf("\nThe nodes reacheable from %d is : ", i);
        dfs(i, n);
    }
}