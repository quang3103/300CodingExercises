#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;
    int mid = 0;

    while (l<=r) {
        mid = (l+r)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    return (-1);
}

int main() {
    int a[]={1,2,3,4,5};

    printf("search: %d", search(a, sizeof(a)/sizeof(int), 5));

    return 0;
}