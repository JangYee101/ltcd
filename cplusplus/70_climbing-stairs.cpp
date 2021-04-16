#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if (n==0)
            return 0;
        if (n==1)
            return 1;
        if (n==2)
            return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        int pre=1, tail=2, tmp;
        if(n<3) return n;
        n -= 2;
        while(n--) {
            tmp = tail;
            tail = pre + tail;
            pre = tmp;
        }
        return tail;
    }
};



int main(int argc, char ** argv) {
    int i;
    //vector<int> nums;
    //for(i=1;i<argc;i++) {
    //    nums.push_back(atoi(argv[i]));
    //}
	Solution solution;
	Solution2 solution2;
	//cout << solution.climbStairs(atoi(argv[1])) << endl;
	cout << solution2.climbStairs(atoi(argv[1])) << endl;
	return 0;
}
