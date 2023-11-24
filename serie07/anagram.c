#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Compares two characters ignoring the case
int cmp_ci(char a, char b) {
    int delta = abs(a - b);
    return delta == 32 || delta == 0;
}

// Counts every occurrence of a given letter in a given word
int contains(char* word, char letter) {
    int counter = 0;
    for (int i = 0; i < strlen(word); i++) {
        char currentLetter = *(word + i);
        if (cmp_ci(currentLetter, letter)) counter++;
        
    }
    return counter;
}

int anagram(char* firstStr, char* secondStr) {
    if (strlen(firstStr) != strlen(secondStr)) return 0;

    for (int i = 0; i < strlen(firstStr); i++) {
        char currentLetter = *(firstStr + i);
        if (contains(firstStr, currentLetter) != contains(secondStr, currentLetter)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char firstStr[64];
    char secondStr[64];

    printf("firstStr=");
    scanf("%s", firstStr);

    printf("secondStr=");
    scanf("%s", secondStr);

    printf("erg=%d\n", anagram(firstStr, secondStr));
    return 0;
}