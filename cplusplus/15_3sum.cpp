#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;


void showVector(vector<int>& nums) {
    int size=nums.size(), i;
    for(i=0;i<size;i++)
        cout<< nums[i] << " ";
    cout << endl;
}



class Solution {
public:
    vector<int> _sort(vector<int>& nums) {
        int i, j, size = nums.size(), t;
        for(i=1;i<size;i++) {
            for(j=i;j>0;j--) {
                if(nums[j] < nums[j-1]) {
                    t = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = t;
                }
                else
                    break;
            }
        }
        return nums;
    }

    void _push_back(vector<vector<int>> &res, vector<int> *p) {
        int size=res.size(), i;
        for(i=size-1; i>=0; i--) {
            if(res[i][1] == p->at(1) && res[i][0] == p->at(0)) {
                return ;
            }
            if(res[i][1] != p->at(1))
                break;
        }
        res.push_back(*p);
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        _sort(nums);
		vector<vector<int>> res;
        int size=nums.size(), i, j=0, splitI = 0, preI, tailI;
        if(size<3 || nums[0]>0 || nums[size-1]<0) return res;
        int mid = 1, sum;
        while(nums[splitI]<0) splitI++;
        vector<int> *p;
        if(splitI+2 < size && nums[splitI+2] == 0) res.push_back(*(new vector<int>({0,0,0})));
        while(nums[mid]<0) {
            preI = mid - 1;
            tailI = splitI;
            while(preI>=0 && tailI < size) {
                sum = nums[mid]+nums[preI]+nums[tailI];
                if(sum == 0) {
                    p = new vector<int>({nums[preI], nums[mid], nums[tailI]});
                    _push_back(res, p);
                    preI--;
                    tailI++;
                }
                else if(sum > 0) {
                    preI--;
                }
                else
                    tailI++;
            }
            mid++;
        }
        while(mid<size-1) {
            preI = splitI-1;
            tailI = mid+1;
            while(preI>=0 && tailI < size) {
                sum = nums[mid]+nums[preI]+nums[tailI];
                if(sum == 0) {
                    p = new vector<int>({nums[preI], nums[mid], nums[tailI]});
                    _push_back(res, p);
                    preI--;
                    tailI++;
                }
                else if(sum > 0) {
                    preI--;
                }
                else
                    tailI++;
            }
            mid++;
        }
        return res;
    }
};

int main(int argc, char ** argv) {
    int i,j;
    vector<int> nums;
    for(i =1;i< argc;i++) {
        nums.push_back(atoi(argv[i]));
    }
	Solution solution;
	vector<vector<int>> p = solution.threeSum(nums); 
    for(i=0;i<p.size();i++) {
        showVector(p[i]);
    }
	return 0;
}
