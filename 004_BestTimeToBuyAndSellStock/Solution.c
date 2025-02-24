#include "main.h"

#include <stdio.h>

static int max(int a, int b) {
    return (a > b) ? a : b;
}

#if (SOLUTION == DP_SOLUTION)

int maxProfit(int* prices, int pricesSize) {
    size_t i=0, result=0;
    // calling profit[i] is the profit if we buy at (i-1) day and sell at i day.
    // profit[i] = prices[i] - prices[i-1] with i > 0.
    int profit[pricesSize];
    int maxProfit[pricesSize];
    
    for (i=0; i<pricesSize; i++) {
        if (i == 0) profit[i] = 0;
        else profit[i] = prices[i] - prices[i-1];
    }

    // now we can see that if we take profit[i] + profit[i+1] = prices[i] - prices[i-1] + prices[i+1] - prices[i] = prices[i+1] - prices[i-1], and so on...
    // we can only buy once and sell once, so we release that the result will be the maximum of subarray of profit[] array
    // calling maxProfit[i] is the maximum profit we can get at day i
    // maxProfit[i] = max(maxProfit[i-1]+profit[i], profit[i])
    maxProfit[0] = profit[0]; // = 0 :)
    for (i=1; i<pricesSize; i++) {
        maxProfit[i] = max(maxProfit[i-1]+profit[i], profit[i]);
        result = max(maxProfit[i], result);
    }

    return result;
}

#else 

int maxProfit(int* prices, int pricesSize) {
    int currentProfit = 0;
    int currentBuyDay = 0;
    int currentSellDay = 1;

    while (currentSellDay < pricesSize) {
        if (currentProfit < prices[currentSellDay]-prices[currentBuyDay]) {
            currentProfit = prices[currentSellDay]-prices[currentBuyDay];
        }
        if (prices[currentSellDay] < prices[currentBuyDay]) {//try to change buy day for hope
            currentBuyDay = currentSellDay;
            currentSellDay = currentBuyDay + 1;
        }
        else {
            currentSellDay += 1;
        }
    }
    
    return currentProfit;
}

#endif