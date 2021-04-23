#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MININT -2147483648
#define MAXINT 2147483647

class Solution {
public:
    int myAtoi(string s) {
        int startI = 0, endI, num_len = 0, i, len = s.length(), is_up = 1;
        if(len == 0 ) return 0;
        while(startI<len){
            if(s[startI] <= '9' && s[startI] >= '1')
                break;
            startI++;
        }
        if(startI > 0 && s[startI-1] == '-')
            is_up = 0;
        endI = startI+1;
        while(endI<len) {
            if(!(s[endI] <= '9' && s[endI] >= '0'))
                break;
            endI++;
        }
        num_len = endI - startI;
        if(num_len > 10) {
            if(is_up)
                return MAXINT;
            return MININT;
        }
        long num = s[startI] - '0';
        for(i=startI+1;i<endI;i++) {
            num = num*10 + s[i] - '0';
        }
        if(!is_up)  num *= -1;
        if(num > MAXINT) return MAXINT;
        else if(num < MININT) return MININT;
        return num;
    }
};


//TODO: 原题对于"asdf 123"返回为0，该程序返回123，所以提交失败
int main(int argc, char ** argv) {
    string s1 = argv[1];
	Solution solution;
	cout << solution.myAtoi(s1) << endl;   
	return 0;
}
