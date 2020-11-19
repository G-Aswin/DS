#include <stdio.h>

#define SIZE 4

int maze[SIZE][SIZE] = {  { 0, 1, 1, 1 }, 
                    { 0, 0, 1, 0 }, 
                    { 1, 0, 1, 1 }, 
                    { 0, 0, 0, 0 } };

int solution[SIZE][SIZE] = {0};

int solve_maze(int r, int c)
{
    if (r == SIZE - 1 && c == SIZE - 1)
    {
        solution[r][c] = 1;
        return 1;
    }

    if (r >= 0 && c >= 0 && r < SIZE && c < SIZE && solution[r][c] == 0 && maze[r][c] == 0)
    {
        solution[r][c] = 1;

        if (solve_maze(r + 1, c))
            return 1;
        if (solve_maze(r, c + 1))
            return 1;
        if (solve_maze(r - 1, c))
            return 1;
        if (solve_maze(r, c - 1))
            return 1;

        solution[r][c] = 0;
        return 0;
    }

    return 0;
}

void print_matrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", matrix[i][j]);
        
        printf("\n");
    }
}

int main()
{
    printf("\nThe maze is : \n");
    print_matrix(maze);

    solve_maze(0, 0);

    printf("\nThe answer matrix is : \n");
    print_matrix(solution);
    return 0;
}