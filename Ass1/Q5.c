#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    
    int arr[r][c];
    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    
    printf("\nRow sums:\n");
    for(int i = 0; i < r; i++) {
        int rowSum = 0;
        for(int j = 0; j < c; j++)
            rowSum += arr[i][j];
        printf("Row %d: %d\n", i+1, rowSum);
    }
    
    printf("\nColumn sums:\n");
    for(int j = 0; j < c; j++) {
        int colSum = 0;
        for(int i = 0; i < r; i++)
            colSum += arr[i][j];
        printf("Column %d: %d\n", j+1, colSum);
    }
    
    return 0;
}