#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubArray(int* nums, int numsSize) {
    int* a = (int*)malloc(numsSize*sizeof(int));
    size_t i = 0;
    int result;

    a[0] = nums[0];
    result = a[0];
    for(i=1; i<numsSize; i++) {
        a[i] = max(a[i-1]+nums[i], nums[i]);
        result = max(result, a[i]);
    }    
    return result;
}

int main() {
    int a[] = {1,2,3,4};

    printf("%d", maxSubArray(a, sizeof(a)/sizeof(int)));

    return 0;
}