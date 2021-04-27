#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int len = s.length(), i=0, j=0;
        bool hs=false;
        //del mul space
        while(s[i] == ' ') i++;
        for(;i<len;i++) {
            if(s[i] == ' ') {
                if(hs)
                    continue;
                hs = true;
            }
            else
                hs = false;
            s[j] = s[i];
            j++;
        }
        if(s[j-1] == ' ')
            j--;
        s.resize(j);
        len = s.length();
        if(len == 0)
            return "";
        //reverse all
        reverse(s.begin(), s.end());
        //reverse word
        j=0;
        for(i=0;i<len;i++) {
            if(s[i]==' ') {
                reverse(s.begin()+j, s.begin()+i);
                j = i+1;
            }
        }
        reverse(s.begin()+j, s.begin()+i);
        return s;
    }
};


int main(int argc, char ** argv) {
    string s1 = " hello jiangye ";
    Solution solution;
	cout << "|" << solution.reverseWords(s1) << "|" << endl;;
	return 0;
}
