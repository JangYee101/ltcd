#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length(), i, j, maxl=0, maxj=-1;
        for(i=0;i<len;i++) {
            j=i-1;
            while(j>=0) {
                if(s[j] == s[i])
                    break;
                j--;
            }
            maxj = maxj>j?maxj:j;
            maxl = maxl>(i-maxj)?maxl:(i-maxj);
            //cout << "i:" << i <<"\t j:" << j << endl;
            //cout << "maxl: " << maxl << endl;
        }
        return maxl;
    }
};




int main(int argc, char ** argv) {
    string s1 = argv[1];
	Solution solution;
	cout << solution.lengthOfLongestSubstring(s1) << endl;   
	return 0;
}
