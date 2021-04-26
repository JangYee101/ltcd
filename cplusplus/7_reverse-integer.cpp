#include <iostream>
using namespace std;

#define MAXINT 2147483647
#define MININT -2147483648



class Solution {
public:
    int reverse(int x) {
        int res = 0, t;
        while(x){
            t = x%10;
            x /= 10;
            if(res > MAXINT/10 || (res == MAXINT/10 && t > 7))
                return 0;
            if(res < MININT/10 || (res == MININT/10 && t < -8))
                return 0;
            res = 10*res + t;
        }
        return res;
    }
};


int main()
{
    Solution solution;
    cout << solution.reverse(123) << endl;
    cout << solution.reverse(-123) << endl;
    return 0;
}
