#include <stdio.h>
#include <string.h>
void patternMatching(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int found = 0;
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLength) { // Pattern found
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Pattern not found in the text.\n");
    }
}
int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%[^\n]%*c", text); // To read a line of input
    printf("Enter the pattern: ");
    scanf("%[^\n]", pattern);

    patternMatching(text, pattern);

    return 0;
}
