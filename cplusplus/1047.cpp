#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> res;
        int len = S.length(), i;
        if(len < 2) return S;
        res.push(S[0]);
        for(i=1;i<len;i++) {
            if(res.empty() || S[i] != res.top())
                res.push(S[i]);
            else
                res.pop();
        }
        string s1="";
        while(!res.empty()) {
            s1 += res.top();
            res.pop();
        }
        reverse(s1.begin(), s1.end());
        return s1;
    }
};


int main(int argc, char ** argv) {
    string s1 = "abbaca";
    Solution solution;
    cout << solution.removeDuplicates(s1) << endl;
	return 0;
}











