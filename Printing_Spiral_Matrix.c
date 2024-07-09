#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;

    printf("Enter the number of rows (1-9): ");
    while (scanf("%d", &row) != 1 || row < 1 || row > 9)
    {
        printf("Invalid input for rows. Please enter a number between 1 and 9.\n");
        while (getchar() != '\n'); 
    }

    printf("Enter the number of columns (1-9): ");
    while (scanf("%d", &col) != 1 || col < 1 || col > 9) {
        printf("Invalid input for columns. Please enter a number between 1 and 9.\n");
        while (getchar() != '\n'); 
    }

    int **Matrix = (int **)malloc(sizeof(int *) * row);
    if (Matrix == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < row; i++) 
    {
        Matrix[i] = (int *)malloc(sizeof(int) * col);
        if (Matrix[i] == NULL) 
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &Matrix[i][j]);
        }
    }

    printf("Matrix elements in spiral order: ");
    int i, left = 0, right = col - 1, top = 0, bottom = row - 1;

    while (left <= right && top <= bottom) {
        // Print top row
        for (i = left; i <= right; i++) {
            printf("%d ", Matrix[top][i]);
        }
        top++;

        for (i = top; i <= bottom; i++) {
            printf("%d ", Matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (i = right; i >= left; i--) {
                printf("%d ", Matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                printf("%d ", Matrix[i][left]);
            }
            left++;
        }
    }

    for (int i = 0; i < row; i++) {
        free(Matrix[i]);
    }
    free(Matrix);

    return 0;
}
