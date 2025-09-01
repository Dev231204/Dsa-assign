#include <stdio.h>

void diagonalMatrix() {
    int n;
    printf("Enter size of diagonal matrix: ");
    scanf("%d", &n);
    int diag[n];
    printf("Enter diagonal elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &diag[i]);
    
    printf("Diagonal matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", (i == j) ? diag[i] : 0);
        }
        printf("\n");
    }
}

void tridiagonalMatrix() {
    int n;
    printf("Enter size of tridiagonal matrix: ");
    scanf("%d", &n);
    int main[n], upper[n-1], lower[n-1];
    
    printf("Enter main diagonal: ");
    for (int i = 0; i < n; i++) scanf("%d", &main[i]);
    printf("Enter upper diagonal: ");
    for (int i = 0; i < n-1; i++) scanf("%d", &upper[i]);
    printf("Enter lower diagonal: ");
    for (int i = 0; i < n-1; i++) scanf("%d", &lower[i]);
    
    printf("Tridiagonal matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) printf("%d ", main[i]);
            else if (j == i+1) printf("%d ", upper[i]);
            else if (j == i-1) printf("%d ", lower[j]);
            else printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    diagonalMatrix();
    tridiagonalMatrix();
    return 0;
}