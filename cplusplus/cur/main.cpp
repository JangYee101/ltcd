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
    ListNode* reverseList(ListNode * l) {
        ListNode *p=l;
        while(l) {
                    
        }
        p = l->next;
        l->next = l
        retur NULL;
    }

    ListNode* _addTwoNumbers(ListNode* l1, ListNod* l2) {

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *res;

        return reverseList(res);
    }
};


int main(int argc, char ** argv) {
    int i;
    vector<int> nums1={2,4,3}, nums2 = {5,6,4};
    ListNode *l1=NULL, *l2=NULL;
    for(i=0;i<3;i++) {
        l1 = new ListNode(nums1[i], l1);
        l2 = new  ListNode(nums2[i], l2);
    }
	Solution solution;
	ListNode *p = solution.addTwoNumbers(l1, l2);
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }
	return 0;
}



