#include <stdio.h>
#include <string.h>
#include <ctype.h>

void concatenateStrings() {
    char str1[100], str2[100];
    printf("Enter first string: "); gets(str1);
    printf("Enter second string: "); gets(str2);
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
}

void reverseString() {
    char str[100];
    printf("Enter string: "); gets(str);
    printf("Reversed string: ");
    for (int i = strlen(str)-1; i >= 0; i--) printf("%c", str[i]);
    printf("\n");
}

void removeVowels() {
    char str[100], result[100];
    printf("Enter string: "); gets(str);
    int j = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    printf("String without vowels: %s\n", result);
}

void sortStrings() {
    char strings[5][100], temp[100];
    printf("Enter 5 strings:\n");
    for (int i = 0; i < 5; i++) gets(strings[i]);
    
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 5; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }
    printf("Sorted strings:\n");
    for (int i = 0; i < 5; i++) printf("%s\n", strings[i]);
}

void toLowerCase() {
    char c;
    printf("Enter uppercase character: ");
    scanf("%c", &c);
    printf("Lowercase: %c\n", tolower(c));
}

int main() {
    concatenateStrings();
    reverseString();
    removeVowels();
    sortStrings();
    toLowerCase();
    return 0;
}