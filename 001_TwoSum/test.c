#include <stdio.h>
#include <stdlib.h>

typedef struct _pair {
    int value;
    int idx;
} myPair;

void swap(myPair* a, myPair* b)
{
    myPair temp = *a;
    *a = *b;
    *b = temp;
}

int partition(myPair* arr, int low, int high)
{
    int latestIndexThatHasValueSmallerThanPivot = low - 1;
    int iterator = low;
    int current = 0, pivot = 0;

    while (iterator < high)
    {
        current = arr[iterator].value;
        pivot = arr[high].value;
        if (current < pivot)
        {
            latestIndexThatHasValueSmallerThanPivot += 1;
            swap(&arr[latestIndexThatHasValueSmallerThanPivot], &arr[iterator]);
        }
        iterator += 1;
    }

    swap(&arr[latestIndexThatHasValueSmallerThanPivot+1], &arr[high]);
    return latestIndexThatHasValueSmallerThanPivot+1;
}

void quickSort(myPair* arr, int low, int high)
{
    int pivot = 0;
    if (low < high)
    {
        pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int binarySearch(myPair* arr, int target, int low, int high)
{
    int mid = (low+high)/2;
    if (low > high) return (-1);
    if (target == arr[mid].value) return mid;
    if (target < arr[mid].value)
        return binarySearch(arr, target, low, mid-1);
    return binarySearch(arr, target, mid+1, high);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i=0, j=0;
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int)*(*returnSize));
    myPair* storage = (myPair*)malloc(sizeof(myPair)*(numsSize));
    
    for (i=0; i<numsSize; i+=1)
    {
        myPair newPair = {.value=nums[i], .idx=i};
        storage[i] = newPair;
    }

    quickSort(storage, 0, numsSize-1);
    
    i=0;
    j=numsSize-1;   
    while (i<j)
    {
        int sum = storage[i].value+storage[j].value;
        if (sum == target)
        {
            result[0] = storage[i].idx;
            result[1] = storage[j].idx;
            break;
        }

        if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return result;
}
int main()
{
    int a[3] = {3,2,4};
    int target = 6;
    int s = 0;
    int* kq;
    int i=0;
    kq = twoSum(a, sizeof(a)/sizeof(int), target, &s);
    for (i=0; i<s; i+=1) printf("%d ", kq[i]);
}
