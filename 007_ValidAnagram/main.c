#include <stdbool.h>
#include <stdio.h>

bool isAnagram(char* s, char* t) {
    size_t counter[26];
    size_t i=0;
    size_t lenS = strlen(s);
    size_t lenT = strlen(t);
    memset(counter, 0, sizeof(counter));

    if (lenS != lenT) return false;
    for (i=0; i<lenS; i++) {
        counter[(s[i]-'a')] += 1;
    }

    for (i=0; i<lenT; i++) {
        if (counter[(t[i]-'a')] > 0) {
            counter[(t[i]-'a')] -= 1;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    char s[] = "anagram";
    char t[] = "nagaram1";

    printf("isAnagram: %d\n", isAnagram(s, t));
    
    return 0;
}