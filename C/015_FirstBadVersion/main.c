#include <stdio.h>
#include <stdbool.h>

int n = 5;
int bad = 4;

bool isBadVersion(int version) {
    if (version >= bad) return true;
    return false;
}

int firstBadVersion(int n) {
    unsigned long l=1;
    unsigned long h=n;
    unsigned long m;
    while (l < h) {
        m = (l+h);
        m /= 2;
        if (isBadVersion(m)) {
            h = m;
        }
        else {
            l = m + 1;
        }
    }
    return h;
}

int main(void) {
    printf("first bad version: %d\n", firstBadVersion(n));
    return 0;
}