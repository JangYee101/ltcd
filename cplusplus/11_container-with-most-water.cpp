#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;



class SolutionFull {
public:
    int maxArea(vector<int>& height) {
        int j,i,len = height.size(), maxW=0, minh, curW;
        for(i=0;i<len;i++) {
            for(j=i+1;j<len;j++) {
                minh = height[i]<height[j]?height[i]:height[j];
                curW = minh*(j-i);
                if(maxW<curW)
                    maxW = curW;
            }
        }
        return maxW;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int headI = 0, size = height.size(), tailI = size-1, maxW=0, curW, minI;
        while(headI < tailI){
            if(height[headI]>height[tailI]) {
                curW = (tailI - headI) * height[tailI] ;
                tailI--;
            }
            else {
                curW = (tailI - headI) * height[headI] ;
                headI++;

            }
            if(curW > maxW)
                maxW = curW;
        }
        return maxW;
    }
};


int main(int argc, char ** argv) {
    vector<int> nums;
    for(int i =1;i< argc;i++) {
        nums.push_back(atoi(argv[i]));
    }
	Solution solution;
	cout << solution.maxArea(nums) << endl;   
	return 0;
}
