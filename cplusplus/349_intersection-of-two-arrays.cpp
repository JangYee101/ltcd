#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> res;
        int size = nums2.size();
        for(int i=0;i<size;i++) {
            if(set1.find(nums2[i]) != set1.end())
                res.insert(nums2[i]);
        }
        return vector<int> (res.begin(), res.end());
    }
};



int main(int argc, char ** argv) {
    vector<int> nums1 {1,2,3,4,4}, nums2 {3, 4};
	Solution solution;
	vector<int> res = solution.intersection(nums1, nums2);
    for(int i=0;i<res.size();i++)
        cout << res[i] << endl;

	return 0;
}
