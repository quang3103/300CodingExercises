#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool isAlphanumeric(char c) {
    if ((c >= 'a') && (c <= 'z')) return true;
    if ((c >= 'A') && (c <= 'Z')) return true;
    if ((c >= '0') && (c <= '9')) return true;
    return false;
}

static char lowerCaser(char c) {
    if ((c >= 'A') && (c <= 'Z'))
        return c + ('a'-'A');
    else 
        return c;
}

bool isPalindrome(char* s) {
    size_t len = strlen(s);
    int l = 0, r = len-1;
    while (l <= r) {
        if ((isAlphanumeric(s[l])) && (isAlphanumeric(s[r]))) {
            if (lowerCaser(s[l]) != lowerCaser(s[r])) {
                return false;
            }
            else {
                l++;
                r--;
            }
        }
        else {
            if (!isAlphanumeric(s[l])) l++;
            if (!isAlphanumeric(s[r])) r--;
        }
    }
    return true;
}

int main() {
    char s[] = "A man, a plan, a canal: Panama1";
    printf("isPalindrome: %d\n", isPalindrome(s));
}