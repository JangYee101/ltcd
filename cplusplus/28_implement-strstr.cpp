#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length(), maxI = len1-len2, i , j;
        const char * s1 = haystack.c_str(), *s2 = needle.c_str();
        for(i=0;i<=maxI;i++) {
            for(j=0;j<len2;j++) {
                if(s1[i+j] != s2[j])
                    break;
            }
            //find
            if(j == len2) {
                break;
            }
        }
        if(i>maxI) return -1;
        return i;
    }
};


int main(int argc, char ** argv) {
    string str=string("jiangye3");
    string sub=string("yee");
	Solution solution;
	int new_index = solution.strStr(str, sub);
    cout << new_index << endl;
    cout << str.find(sub) << endl;
	return 0;
}
