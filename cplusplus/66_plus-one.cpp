#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, size = digits.size(), is_overflow=1;
        for(i=size-1;i>=0;i--) {
            if(is_overflow == 0)
                break;
            if(digits[i] == 9) {
                digits[i] = 0;
                continue;
            }
            digits[i]++;
            is_overflow = 0;
        }
        if(is_overflow)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};


int main(int argc, char ** argv) {
    int i;
    vector<int> nums;
    for(i=1;i<argc;i++) {
        nums.push_back(atoi(argv[i]));
    }
	Solution solution;
	solution.plusOne(nums);
    int size = nums.size();
	for(i=0;i<size;i++) {
        cout << nums[i] << endl;
    }
	return 0;
}
