#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        //reverse(s.begin(), s.end());
        int i=0, len = s.length();
        while(i+2*k<len) {
            reverse(s.begin()+i, s.begin() + i + k);
            i += 2*k;
        }
        if(i!=len) {
            if(i+k > len)
                reverse(s.begin()+i, s.end());
            else
                reverse(s.begin()+i, s.begin()+i+k);
        }
        return s;
    }
};


int main(int argc, char ** argv) {
    string s1 = "hello jiangy";
    Solution solution;
	cout << solution.reverseStr(s1, 2) << endl;;
	return 0;
}
