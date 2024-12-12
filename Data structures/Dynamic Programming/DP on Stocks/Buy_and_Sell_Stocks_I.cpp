#include <iostream>
#include <vector>
using namespace std;

// In this question, you can do only one transaction (buy-sell), such that the profit is maximum.


int maximumProfit(vector<int> &prices){
    int minimumPrice = prices[0];
    int maximumProfit = 0;
    for(int i = 1; i < prices.size(); i++) {
        maximumProfit = max(maximumProfit, prices[i] - minimumPrice);
        minimumPrice = min(minimumPrice, prices[i]);
    }
    return maximumProfit;   
}
int main() {
    vector<int> prices = {120, 250, 20, 120, 80};
    cout << maximumProfit(prices) << endl;
    return 0;
}