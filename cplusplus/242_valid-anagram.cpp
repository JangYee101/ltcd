#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> res(26, 0);
        int size = s.length(), i;
        for(i=0;i<size;i++) {
            res[s[i]-'a']++;
            res[t[i]-'a']--;
        }
        for(i=0;i<26;i++) {
            if(res[i] != 0)
                return false;
        }
        return true;
    }
};



int main(int argc, char ** argv) {
    string s1=argv[1], s2=argv[2];
	Solution solution;
	cout << solution.isAnagram(s1, s2) << endl;   
	return 0;
}
