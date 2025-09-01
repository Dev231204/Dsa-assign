#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, value;
} Triple;

void transposeSparse(Triple a[], Triple b[]) {
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;
    
    int k = 1;
    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= a[0].value; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].value = a[j].value;
                k++;
            }
        }
    }
}

int main() {
    Triple a[MAX] = {{3, 3, 4}, {0, 1, 3}, {1, 0, 2}, {1, 2, 5}, {2, 1, 4}};
    Triple b[MAX];
    
    transposeSparse(a, b);
    printf("Transpose:\n");
    for (int i = 1; i <= b[0].value; i++) {
        printf("(%d, %d, %d)\n", b[i].row, b[i].col, b[i].value);
    }
    return 0;
}
