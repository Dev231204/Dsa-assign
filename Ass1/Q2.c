#include <stdio.h>

int arr[100], n = 0;

void create() {
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void display() {
    if(n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert() {
    if(n >= 100) {
        printf("Array is full!\n");
        return;
    }
    
    int pos, elem;
    printf("Enter position to insert (1 to %d): ", n+1);
    scanf("%d", &pos);
    
    if(pos < 1 || pos > n+1) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Enter element to insert: ");
    scanf("%d", &elem);
    
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    
    arr[pos-1] = elem;
    n++;
    printf("Element inserted successfully!\n");
}

void deleteElement() {
    if(n == 0) {
        printf("Array is empty!\n");
        return;
    }
    
    int pos;
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);
    
    if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Deleted element: %d\n", arr[pos-1]);
    
    for(int i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    
    n--;
    printf("Element deleted successfully!\n");
}

void linearSearch() {
    if(n == 0) {
        printf("Array is empty!\n");
        return;
    }
    
    int elem, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &elem);
    
    for(int i = 0; i < n; i++) {
        if(arr[i] == elem) {
            printf("Element found at position %d\n", i+1);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Element not found!\n");
    }
}

void removeDuplicates() {
    if(n == 0) {
        printf("Array is empty!\n");
        return;
    }
    
    int newSize = 0;
    
    for(int i = 0; i < n; i++) {
        int isDuplicate = 0;
        
        for(int j = 0; j < newSize; j++) {
            if(arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        
        if(!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    
    n = newSize;
    printf("Duplicates removed successfully! New array size: %d\n", n);
}

int main() {
    int choice;
    
    while(1) {
        printf("\n——MENU——-\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. REMOVE DUPLICATES\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                linearSearch();
                break;
            case 6:
                removeDuplicates();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}