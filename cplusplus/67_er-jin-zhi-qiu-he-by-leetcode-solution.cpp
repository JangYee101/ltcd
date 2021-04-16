#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length(), len_b = b.length(), len_min=len_a, len_max=len_b, index = 1, i, is_overflow=0;
        string *max_str = &b;
        char z = '0';
        int twoz = 2*z;
        int twoadd = 0;
        if(len_a > len_b) {
            len_min = len_b;
            len_max = len_a;
            max_str = &a;
        }
        string res(len_max, '9');
        for(i=len_min;i>0;i--,index++) {
            twoadd = a[len_a-index] + b[len_b-index] + is_overflow - twoz;
            cout << twoadd << endl;
            if( twoadd > 1) {
                is_overflow = 1;
                res[len_max-index] = (twoadd % 2) + '0';
                continue;
            }
            res[len_max-index] = a[len_a-index]>b[len_b-index]?a[len_a-index]:b[len_b-index];
            res[len_max-index] += is_overflow;
            is_overflow = 0;
        }
        for(i=len_max; i>len_min;i--,index++) {
            if(is_overflow == 0) {
                res[len_max-index] = (*max_str)[len_max-index];
                break;
            }
            if((*max_str)[len_max-index] == '1') {
                res[len_max-index] = '0';
                continue;
            }
            res[len_max-index] = '1';
            is_overflow = 0;
            
        }
        for(;i>len_min;i--,index++)
            res[len_max-index] = (*max_str)[len_max-index];

        if(is_overflow) {
            res.insert(0, "1");
        }
        return res;
    }
};
//TODO:可以考虑在短数前补零，这样一个for就完成了，不用那么多逻辑
int main(int argc, char ** argv) {
    int i;
    //vector<int> nums;
    //for(i=1;i<argc;i++) {
    //    nums.push_back(atoi(argv[i]));
    //}
	string s1 = argv[1], s2 = argv[2];
	Solution solution;
	cout << solution.addBinary(s1, s2) << endl;
	return 0;
}
