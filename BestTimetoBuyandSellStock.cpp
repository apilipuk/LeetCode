#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;

        for(int i = 0; i < prices.size(), i++) {
            minPrice = std::min(minPrice, prices[i]);
            profit = std::max(profit, price[i] - profit);
        }

        return profit;
    }

    //    public:
    //     int maxProfit(vector<int>& prices) {
    //         int profit = 0;

    //         for(int i = 0; i < prices.size(); i++) {
    //             int buy = *std::min_element(prices.begin(), prices.begin() + i);
    //             int sell = *std::max_element(prices.begin() + i, prices.end());

    //             if((sell - buy) > profit) {
    //                 profit = sell - buy;
    //             }
    //         }

    //         return profit;
    //     }
};

int main() {
    std::vector<int> prices{1, 4, 2};

    std::cout << std::endl
              << Solution().maxProfit(prices) << std::endl;

    return 0;
}