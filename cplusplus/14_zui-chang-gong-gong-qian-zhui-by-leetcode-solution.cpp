#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //string res_str = "";
        //for(vector<string>::iterator str = strs.begin(); str!= strs.end(); str++)
        //    res_str += *str;
        //return res_str;
        
        int count = strs.size();
        if(count == 0)
            return "";
        int length = strs[0].size();
        int t;
        char tmp;
        for(vector<string>::iterator s=strs.begin()+1;s!= strs.end();s++) {
            t = (*s).size();
            length = (length<t)?length:t;
        }
        int index;
        for(index=0;index<length;index++) {
            tmp = strs[0][index];
            for(vector<string>::iterator s=strs.begin()+1;s!= strs.end();s++) {
                if(tmp != (*s)[index]) {
                    return strs[0].substr(0, index);
                }
            }
        }
        return strs[0].substr(0, index);
    }
};

int main() {
    Solution solution;
    vector<string> strs;
    //strs.push_back(string("Hello "));
    //strs.push_back(string("Hello world\n"));
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
