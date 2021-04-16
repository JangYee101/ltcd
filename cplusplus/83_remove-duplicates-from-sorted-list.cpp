#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode *p = head;
        while(p->next) {
            if(p->val == p->next->val) {
                //cout << "del " << p->val << endl;
                p->next = p->next->next;
            }
            else
                p = p->next;
        }
        return head;
    }
};


int main(int argc, char ** argv) {
    int i;
    ListNode *head = new ListNode(atoi(argv[argc-1]));
    vector<int> nums;
    for(i=argc-2;i>0;i--) {
        head = new ListNode(atoi(argv[i]), head);
    }
	Solution solution;
	ListNode *p = solution.deleteDuplicates(head);
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }
	return 0;
}
