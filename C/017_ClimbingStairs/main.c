#include <stdio.h>

int climbStairs(int n) {
    //define ways[i] is the number of ways to step to i stair.
    //at i stair, we can only go from stair (i-1) or stair (i-2) due to 1 step or 2 steps once
    //ways[i] = ways[i-1] + ways[i-2]
    //ways[1] = 1, ways[2] = 2
    static int ways[46]; //without remembering the ways, time limit exceeded will happen :)

    if (n <= 2) {
        ways[n] = n;
        return ways[n];
    }
    if (ways[n-1] == 0) ways[n-1] = climbStairs(n-1);
    if (ways[n-2] == 0) ways[n-2] = climbStairs(n-2);
    ways[n] = ways[n-1] + ways[n-2];
    return ways[n];
} 

int main(void) {
    int n = 6;
    printf("Ways to go to %d stair: %d\n", n, climbStairs(n));
    return 0;
}