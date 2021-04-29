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
    void _mySort(vector<int>& nums) {
        int i, j, size = nums.size();
        for(i=1;i<size;i++) {
            for(j=i;j>0;j--) {
                if(nums[j-1] > nums[j])
                    swap(nums[j-1], nums[j]);
                else
                    break;
            }
        }
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        _mySort(g);
        _mySort(s);
        int g_tailI = g.size()-1, s_tailI = s.size()-1, i, j;
        int res=0;
        for(;g_tailI>=0;g_tailI--) {
            if(g[g_tailI] <= s[s_tailI]) {
                res++;
                s_tailI--;
            }
        }
        return res;
    }
};


int main(int argc, char ** argv) {
    vector<int> childs {1, 2}, kics {1,2,3};
    Solution solution;
    cout << solution.findContentChildren(childs, kics) << endl;
	return 0;
}









