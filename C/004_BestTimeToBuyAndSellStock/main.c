#include <stdio.h>
#include "main.h"

int main() {
    int a[] = {7,1,5,3,6,9};
    printf("Max profit: %d\n", maxProfit(a, sizeof(a)/sizeof(int)));
    return 0;
}