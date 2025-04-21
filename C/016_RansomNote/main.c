#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int a[26];
    int len_a, len_b, i;
    memset(a, 0, sizeof(a));
    len_a = strlen(ransomNote);
    len_b = strlen(magazine);

    for (i=0; i<len_b; i++) {
        a[magazine[i]-'a'] += 1;
    }

    for (i=0; i<len_a; i++) {
        if (a[ransomNote[i]-'a'] == 0) return false;
        a[ransomNote[i]-'a'] -= 1;
    }

    return true;
}

int main(void) {
    char a[] = "aa";
    char b[] = "a";

    printf("Result: %d\n", canConstruct(a, b));
    return 0;
}