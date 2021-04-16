#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0, max=1<<31, size = nums.size();
        for(int i=0;i<size;i++) {
            pre = pre>0?(pre+nums[i]):nums[i];
            max = max>pre?max:pre;
        }
        return max;
    }
};


int main(int argc, char ** argv) {
    int i;
    vector<int> nums;
    for(i=1;i<argc;i++) {
        nums.push_back(atoi(argv[i]));
    }
	Solution solution;
	int max_sum = solution.maxSubArray(nums);
    cout << max_sum << endl;
	return 0;
}
