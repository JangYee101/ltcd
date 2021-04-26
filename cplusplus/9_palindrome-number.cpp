#include <iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        int x_num = 0;
        if(x < 0)
            return false;
        long int mid = 1;
        while(x/mid)
        {
            mid *= 10;
            x_num++;
        }
        x_num /= 2;
        //cout << x << "  " << x_num << endl;
        while(x_num--) {
            mid /= 10;
            //cout << "x is " << x << "\t mid is " << mid << endl;
            //cout << "x%10 is " << x%10 << "\t x/mid is " << x/mid << endl;
            if(x%10 != x/mid)
                return false;
            x /= 10;
            mid /= 10;
            x %= mid;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.isPalindrome(121) << endl;
    cout << solution.isPalindrome(1211) << endl;
    cout << solution.isPalindrome(1234567899) << endl;
    cout << solution.isPalindrome(10) << endl;
    return 0;
}
