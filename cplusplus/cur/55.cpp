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
    bool canJump(vector<int>& nums) { 
        int size = nums.size()-1, i=1, maxI = 0;
        maxI = maxI>nums[0]?maxI:nums[0];
        for(;i<=maxI;i++) {
            if(maxI>=size) return true;
            maxI = maxI>(nums[i] + i)?maxI:(nums[i]+i);
        }
        return false;
    }
};

int main(int argc, char ** argv) {
    vector<int> prices {1,1,5,3,6,4}; //7
    Solution solution;
    cout << solution.canJump(prices) << endl;
	return 0;
}









