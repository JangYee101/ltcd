#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int, int> res;
        int size = nums1.size(), i, j, sum, count = 0;
        for(i=0;i<size;i++) {
            for(j=0;j<size; j++) {
                sum = nums1[i] + nums2[j];
                if(res.find(sum) != res.end())
                    res[sum]++;
                else
                    res.insert({sum, 1});
            }
        }
        for(i=0;i<size;i++) {
            for(j=0;j<size;j++) {
                sum = 0 - (nums3[i] + nums4[j]);
                if(res.find(sum) != res.end())
                    count += res[sum];
            }
        }
        return count;
    }
};


int main(int argc, char ** argv) {
    vector<int> nums;
    int i;
    for(i=-5; i< 6; i++) {
        nums.push_back(i);
    }
    vector<int> nums1 {-1,-1};
    vector<int> nums2 {-1,1};
    vector<int> nums3 {-1,1};
    vector<int> nums4 {1,-1};
	Solution solution;
	cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;;
	return 0;
}
