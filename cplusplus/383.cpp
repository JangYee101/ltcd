#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        int len1 = ransomNote.length(), len2 = magazine.length(), i, j;
        for(i=0;i<len2;i++) {
            record[magazine[i]-'a']++;
        }
        for(i=0;i<len1;i++) {
            if(record[ransomNote[i]-'a'] < 1)
                return false;
            record[ransomNote[i]-'a']--;
        }
        return true;
    }
};

int main(int argc, char ** argv) {
    string s1 = "hellos";
    string s2 = "lloheaa";
    Solution solution;
	cout << solution.canConstruct(s1, s2) << endl;;
	return 0;
}
