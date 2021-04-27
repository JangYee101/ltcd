#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stdlib.h>
#include <deque>
using namespace std;


class MyMaxQue {
public:
    deque<int> maxq;        
    void pop(int v) {
        if(!maxq.empty() && v == maxq.front())
            maxq.pop_front();
    }

    void push(int v) {
        while(!maxq.empty() && v > maxq.back()) {
            maxq.pop_back();
        }
        maxq.push_back(v);
    }

    int  front() {
        return maxq.front();
    }
    
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyMaxQue maxq;
        vector<int> res;
        int size = nums.size(), i;
        for(i=0;i<k;i++)
            maxq.push(nums[i]);
        res.push_back(maxq.front());
        for(;i<size;i++) {
            maxq.pop(nums[i-k]);
            maxq.push(nums[i]);
            res.push_back(maxq.front());
        }
        return res;
    }
};


int main(int argc, char ** argv) {
    vector<int> nums;
    int i;
    for(i=1;i<argc-1;i++)
        nums.push_back(atoi(argv[i]));
    Solution solution;
	nums = solution.maxSlidingWindow(nums, atoi(argv[argc-1]));
    for(i=0;i<nums.size();i++) {
        cout << nums[i] << endl;
    }
	return 0;
}
