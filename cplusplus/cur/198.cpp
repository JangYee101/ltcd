
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;


int maxNum(vector<int> & nums, int startI, int endI) {
    if(startI >=  endI)
        return 0;
    if(startI+1 == endI)
        return nums[startI];
    if(startI+2 == endI)
        return nums[startI]>nums[startI+1]?nums[startI]:nums[startI+1];
    int i, max_num=0, l_max, r_max, t;
    for(i=startI; i<endI; i++) {
        l_max = maxNum(nums, startI, i-1);
        r_max = maxNum(nums, i+2, endI);
        t = nums[i] + l_max + r_max;
        max_num = max_num>t?max_num:t;
    }
    return max_num;
}

class Solution {
public:
    int rob(vector<int>& nums) {
		return maxNum(nums, 0, nums.size());
    }
};

int main(int argc, char ** argv) {
    int size=argc-1, i;
	vector<int> nums;
    for(i=0;i<atoi(argv[1]);i++) {
        //nums.push_back(atoi(argv[i+1]));
        nums.push_back(i);
    }
    //for(i=0;i<nums.size();i++)
    //    cout << nums[i] << endl;
    Solution solution;
    cout << solution.rob(nums) << endl;
    return 0;
}
