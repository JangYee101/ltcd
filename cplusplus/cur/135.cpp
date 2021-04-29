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
    int candy(vector<int>& ratings) {
        int size = ratings.size(), i;
        vector<int> candys {1};
        for(i=1;i<size;i++) {
            if(ratings[i]>ratings[i-1])
                candys.push_back(candys[i-1]+1);
            else
                candys.push_back(1);
        }
        int sum = candys[size-1];
        for(i=size-2;i>=0;i--) {
            if(ratings[i] > ratings[i+1] && candys[i]<=ratings[i+1])
                candys[i] = candys[i+1] + 1;
            sum += candys[i];
        }
        return sum;
    }
};

int main(int argc, char ** argv) {
    vector<int> gas {1,2,3,4,5}; 
    vector<int> cost {3,4,5,1,2};
    Solution solution;
    cout << solution.candy(cost) << endl;
	return 0;
}









