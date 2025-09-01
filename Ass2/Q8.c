#include <stdio.h>

int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) break;
        }
        if (i == j) count++;
    }
    return count;
}

int main() {
    int arr[] = {5, 2, 7, 2, 5, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Distinct elements: %d\n", countDistinct(arr, n));
    return 0;
}