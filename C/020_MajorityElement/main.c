#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int i;
    int majorNumber = nums[0];
    int count = 1;
    for (i=1; i<numsSize; i++) {
        if (count == 0) {
            majorNumber = nums[i];
            count += 1;
        }
        else {
            if (majorNumber == nums[i]) count += 1;
            else count -= 1;
        }
    }
    return majorNumber;
}

int main(void) {

    printf("testt\n");
    return 0;
}