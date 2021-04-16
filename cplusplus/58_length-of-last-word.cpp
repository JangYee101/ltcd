#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;




class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail_len = 0, stack_top=0, i, len = s.length();
        for(i=0;i<len;i++) {
            if(s[i] == ' ') {
                if(tail_len)
                    stack_top = tail_len;
                tail_len = 0;
                continue;
            }
            tail_len++;
        }
        return tail_len?tail_len:stack_top;
    }
};


//TODO: 从尾部开始向前遍历
int main(int argc, char ** argv) {
    int i;
    vector<int> nums;
    for(i=1;i<argc;i++) {
        nums.push_back(atoi(argv[i]));
    }
    string str = "jiang ye is luckey";
    //string str = "jiang";
	Solution solution;
	int max_sum = solution.lengthOfLastWord(str);
    cout << max_sum << endl;
	return 0;
}
