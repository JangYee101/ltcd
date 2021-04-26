#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector <int> twoSum(vector<int> & nums, int target) {
            int i,j;
            vector<int> res;
            for(i=0;i<nums.size();i++) {
                for(j=i+1;j<nums.size();j++) {
                    if((nums[i]+nums[j]) == target) {
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                }
            }
            return res;
        }
};


int main(int argc, char ** argv) {

    vector<int> nums;
    for(int i=0;i<10;i++) {
        nums.push_back(i);
    }
    int target = 10;
    Solution solution;
    //solution.twoSum(nums, target);
    vector<int> res = solution.twoSum(nums, target);
    for(vector<int>::iterator v=res.begin(); v!=res.end(); v++)
        cout << *v << endl;
    return 0;
}
