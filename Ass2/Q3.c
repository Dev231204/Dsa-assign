#include <stdio.h>

int findMissing(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i+1] - arr[i] != 1) {
            return arr[i] + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int missing = findMissing(arr, n);
    printf("Missing number: %d\n", missing);
    return 0;
}