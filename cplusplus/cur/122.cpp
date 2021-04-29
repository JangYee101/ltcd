#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <algorithm>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        prices.insert(prices.begin(), 1<<30);
        int size=prices.size()-1, i=1, buy_price=0, sell_price=0, all_get=0, pre_prices=0;
        while(i<size) {
            for(;i<size;i++) {
                if(prices[i-1] != prices[i]) pre_prices = prices[i-1];
                if(pre_prices > prices[i] && prices[i] < prices[i+1])  {
                    buy_price = prices[i];
                    break;
                }
            }
            for(;i<size;i++) {
                if(prices[i-1] != prices[i]) pre_prices = prices[i-1];
                if(pre_prices < prices[i] && prices[i] > prices[i+1])  {
                    sell_price = prices[i];
                    break;
                }
            }
            if(sell_price) {
                all_get += (sell_price - buy_price);
                buy_price = 0;
                sell_price = 0;
            }
        }
        if(prices[i] > prices[i-1])
            all_get += (prices[i] - prices[i-1]);
        return all_get;
    }
};

int main(int argc, char ** argv) {
    vector<int> prices {7,1,5,3,6,4}; //7
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
	return 0;
}









