#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int max_index=0, max_len=1;
        int head, tail, len = s.length(), i, j;
        for(i=1;i<len;i++) {
            //奇数个
            head = i-1;
            tail = i+1;
            while(head >=0 && tail < len) {
                if(s[head] != s[tail])
                    break;
                head--;
                tail++;
            }
            if(max_len<((i-head)*2+1)) {
                max_len = (i-head)*2 + 1;
                max_index = head + 1;
            }
            //偶数个
            head = i-1;
            tail = i;
            while(head >=0 && tail < len) {
                if(s[head] != s[tail])
                    break;
                head--;
                tail++;
            }
            if(max_len < (tail - i)*2) {
                max_len = (tail - i) * 2;
                max_index = head + 1;
            }
        }
        return s.substr(max_index, max_len);
    }
};


int main(int argc, char ** argv) {
    string s1 = argv[1];
	Solution solution;
	cout << solution.longestPalindrome(s1) << endl;   
	return 0;
}
