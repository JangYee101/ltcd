#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        char t;
        stack<char> chars;
        map<char, char>  kuo {{'(',')'} , {'[', ']'}, {'{','}'}};
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                chars.push(s[i]);
            else {
                if(chars.empty() || kuo[chars.top()] != s[i])
                    return false;
                chars.pop();
            }
        }
        if(chars.empty())
            return true;
        return false;

    }
};



int main(int argc, char ** argv) {
	Solution solution;
	cout << solution.isValid("(([]))") << endl;   
	cout << solution.isValid("(([]{)})") << endl;   
	cout << solution.isValid("") << endl;   
	cout << solution.isValid("[") << endl;   
	cout << solution.isValid("]") << endl;   
	return 0;
}
