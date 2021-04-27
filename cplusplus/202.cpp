#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> res;
        int sum=0, t;
        while(1) {
            if(n == 1)
                return true;
            while(n) {
                t = n%10;
                sum = sum + t*t;
                n /= 10;
            }
            n = sum;
            sum = 0;
            if(res.find(n) != res.end())
                return false;
            res.insert(n);
        }
        return false;
    }
};


int main(int argc, char ** argv) {
	Solution solution;
	cout << solution.isHappy(atoi(argv[1])) << endl;
	return 0;
}
