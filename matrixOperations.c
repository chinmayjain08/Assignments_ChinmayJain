#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(int *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    return;
}

void flipMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        reverse(*(matrix + i), n);
    }
    return;
}

void rotateMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(*(matrix + i), n);
    }
    
    return;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("invalid\n");
        return 0;
    }
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("invalid\n");
        return 0;
    }

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int valid = 1;
    for (int i = 0; i < m; i++)
    {
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            int row, col;
            scanf("%d %d", &row, &col);
            if (row > n || col > n || row < 1 || col < 1)
            {
                printf("invalid\n");
                valid = 0;
                break;
            }
            if (matrix[row - 1][col - 1] == 0)
            {
                matrix[row - 1][col - 1] = 1;
            }
            else
            {
                matrix[row - 1][col - 1] = 0;
            }
            for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        }
        else if (choice == 2)
        {
            flipMatrix(matrix, n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
        }
        else if (choice == 3)
        {
            rotateMatrix(matrix, n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("invalid\n");
            valid = 0;
            break;
        }
    }

    if (valid)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}