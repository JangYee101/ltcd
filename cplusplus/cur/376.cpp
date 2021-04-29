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
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size(), i, count=2;
        if(size < 3) return size;
        int pre_distance = nums[1] - nums[0], cur_distance;
        for(i=2;i<size;i++) {
            cur_distance = nums[i] - nums[i-1];
            //异号
            if((pre_distance ^ cur_distance) < 0) {
                count++;
                pre_distance = cur_distance;
            }
        }
        return count;
    }
};


int main(int argc, char ** argv) {
    vector<int> nums {1,17,5,10,13,15,10,5,16,8};
    Solution solution;
    cout << solution.wiggleMaxLength(nums) << endl;
	return 0;
}









