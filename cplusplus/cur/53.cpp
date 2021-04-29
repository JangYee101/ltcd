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
    int maxSubArray(vector<int>& nums) { 
        int sum=0, max=1<<31, i, size=nums.size();
        for(i=0;i<size;i++) {
            sum += nums[i];
            max = max>sum?max:sum;
            if(sum <= 0) {
                sum = 0;
            }
        }
        return max;
    }
};


int main(int argc, char ** argv) {
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
	return 0;
}









