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


class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size(), minI = 1<<30, i, curv, sum=0;
        for(i=0;i<size;i++) {
            curv = gas[i] - cost[i];
            sum+=curv;
            if(sum < minI)
                minI = sum;
        }
        if(sum<0) return -1;
        if(minI >= 0) return  0;
        //cout << "minI is " << minI << endl;
        for(i=size-1;i>0;i--) {
            minI += (gas[i] - cost[i]);
            if(minI >= 0)
                return i;
        }
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size(), sum=0, i=0, j=0;
        for(i=0;i<size;i++) {
            sum += (gas[i]-cost[i]);
        }
        if(sum < 0) return -1;
        i=0;
        while(i<size) {
            sum = 0;
            for(j=i;j<size;j++){
                sum += (gas[j]-cost[j-i]);
                if(sum < 0) break;
            }
            if(j == size) return i;
            i = j+1;
        }
        return -2;
    }
};

int main(int argc, char ** argv) {
    vector<int> gas {1,2,3,4,5}; 
    vector<int> cost {3,4,5,1,2};
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost) << endl;
	return 0;
}









