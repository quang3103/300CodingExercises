#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseString(char *a) {
    char head, tail;
    int i =0;
    int len = strlen(a);
    for (i=0; i<len/2; i++) {
        head = a[i];
        tail = a[len-1-i];

        a[i] = tail;
        a[len-1-i] = head;
    }
}

char addOperator(char a, char b, int r1, int *r2) {
    int int_a = a-'0';
    int int_b = b-'0';
    
    *r2 = (int_a+int_b+r1) / 2;
    return ((int_a+int_b+r1) % 2)+'0';
}

char* addBinary(char* a, char* b) { 
    int len_a = strlen(a);
    int len_b = strlen(b);
    int i;
    char *longer, *shorter;

    reverseString(a);
    reverseString(b);
    
    if (len_a > len_b) {
        longer = a;
        shorter = b;
    } 
    else {
        longer = b;
        shorter = a;
    }
    int len = strlen(longer) + 2;
    char *c = (char*)malloc(sizeof(char)*len);
    int r1 = 0;
    int r2;

    for (i=0; i<strlen(longer); i++) {
        if (i >= strlen(shorter)) {
            c[i] = addOperator(longer[i], '0', r1, &r2);
        }
        else {
            c[i] = addOperator(longer[i], shorter[i], r1, &r2);
        }
        r1 = r2;
    }
    if (r1 == 1) {
        c[strlen(longer)] = '1';
        c[strlen(longer)+1] = '\0';
    }
    else {
        c[strlen(longer)] = '\0';
    }
    reverseString(c);
    return (&c[0]);
}

int main(void) {
    char a[] = "11";
    char b[] = "1";
    printf("%s", addBinary(a, b));
}