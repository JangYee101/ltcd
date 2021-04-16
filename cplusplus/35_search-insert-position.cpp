#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int tailI = nums.size()-1, preI=0, midI;
        if(nums[0] > target)
            return 0;
        if(nums[tailI] < target)
            return tailI+1;
        while(1) {
            midI = (tailI+preI) / 2;
            if(nums[midI] == target) {
                return midI;
            }
            else if(nums[midI] > target) {
                if(tailI == midI)
                    return midI;
                tailI = midI;
            }
            else {
                if(preI == midI)
                    return midI+1;
                preI = midI;
            }
        }
        return -1;
    }
};

int main(int argc, char ** argv) {
    int i;
    vector<int> nums;
    for(i=1;i<argc-1;i++) {
        nums.push_back(atoi(argv[i]));
    }
	Solution solution;
	int new_index = solution.searchInsert(nums, atoi(argv[argc-1]));
    cout << new_index << endl;
	return 0;
}
