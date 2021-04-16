#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int pre=0, tail=1;
        for(int tail=1;tail<nums.size();tail++) {
            if(nums[tail]==nums[tail-1]) {
                continue;
            }
            nums[++pre] = nums[tail];
        }
        return pre+1;
    }
};



int main(int argc, char ** argv) {
	vector<int> nums;
	for(int i=1;i<argc;i++)
        nums.push_back(atoi(argv[i]));
	Solution solution;
	int new_size = solution.removeDuplicates(nums);
    for(int i=0;i<new_size;i++)
        cout << nums[i] << endl;
	return 0;
}
