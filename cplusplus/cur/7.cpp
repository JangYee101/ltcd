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
    int sum;
    vector<int> path;
    vector<vector<int>> res;
    void backTrace(vector<int>&nums, int target, int startI) {
        int size = nums.size(), i;
        if(sum > target) return ;
        if(sum == target) {
            res.push_back(path);
            return ;
        }
        for(i=startI;i<size;i++) {
            path.push_back(nums[i]);
            sum += nums[i];
            backTrace(nums, target, i);
            path.pop_back();
            sum -= nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        sum = 0;
        backTrace(candidates, target, 0);
        return res;
    }
};


int main(int argc, char ** argv) {
    vector<int> nums;
    int i, j;
    for(i=1;i<argc-1;i++)
        nums.push_back(atoi(argv[i]));
    Solution solution;
    vector<vector<int>> res = solution.combinationSum(nums, atoi(argv[i]));
    for(i=0;i<res.size();i++) {
        for(j=0;j<res[i].size();j++)
            cout << res[i][j] << " ";
        cout << endl;

    }
	return 0;
}









