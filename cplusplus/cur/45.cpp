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
    int canJump(vector<int>& nums) { 
        int size = nums.size()-1, i=1, maxI = 0, cur_size, step_count=1;
        maxI = cur_size = maxI>nums[0]?maxI:nums[0];
        while(1) {
            if(maxI>=size) return step_count;
            step_count += 1;
            for(;i<=cur_size;i++) {
                if(maxI>=size) return step_count;
                maxI = maxI>(nums[i] + i)?maxI:(nums[i]+i);
            }
            cur_size = maxI;
        }
        return 0;
    }
};

int main(int argc, char ** argv) {
    //vector<int> prices {1,1,5,3,6,4}; //7
    vector<int> prices {2,3,1,1,4}; //7
    Solution solution;
    cout << solution.canJump(prices) << endl;
	return 0;
}









