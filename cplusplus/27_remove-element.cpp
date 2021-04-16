#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int preI=0, tailI=0, size=nums.size();
        while(preI<size && nums[preI]!=val)
            preI++;
        for(tailI=preI+1;tailI<size;tailI++) {
            if(nums[tailI] == val)
                continue;
            nums[preI] = nums[tailI];
            preI++;
        }
        return preI;
    }
};


int main(int argc, char ** argv) {
	vector<int> nums;
    for(int i=1;i<argc-1;i++) {
        nums.push_back(atoi(argv[i]));
    }
	Solution solution;
	int new_size = solution.removeElement(nums, atoi(argv[argc-1]));
    for(int i=0;i<new_size;i++) {
        cout << nums[i] << endl;
    }
	return 0;
}
