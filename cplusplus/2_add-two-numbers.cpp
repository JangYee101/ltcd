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
        if(!l) 
            return NULL;
        ListNode *p=l;
        ListNode *t = p->next, *c;
        p->next = NULL;
        while(t) {
             c = t;
             t = t->next;
             c->next = p;
             p = c;
        }
        return p;
    }

    ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2, int overflow) {
        if(!(l1||l2)) {
            if(overflow)
                return new ListNode(1);
            return NULL;
        }
        int add1=0;
        ListNode *p;
        if(l1) {
            if(!l2) {
                if(overflow == 0)
                    return l1;
                add1 = 0;
                p=NULL;
            }
            else {
                add1 = l2->val;
                p = l2->next;

            }
            l1->val += (overflow + add1);
            if(l1->val>9) {
                l1->val %= 10;
                overflow = 1;
            }
            else overflow = 0;
            l1->next = _addTwoNumbers(l1->next, p, overflow);
            return l1;
        }
        else {
            if(overflow == 0)
                return l2;
            l2->val += overflow;
            if(l2->val>9) {
                l2->val %= 10;
                overflow = 1;
            }
            else overflow = 0;
            l2->next = _addTwoNumbers(NULL, l2->next, overflow);
            return l2;
        }
        return NULL;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *res = _addTwoNumbers(l1, l2, 0);
        //return reverseList(res);
        return res;
    }
};


//TODO:想复杂了，1.不需要逆序链表；2.不能改变原链表；提交错误但手动运行正确
int main(int argc, char ** argv) {
    int i;
    vector<int> nums1={2,4,9}, nums2 = {5,6,4,9};
    ListNode *l1=NULL, *l2=NULL;
    for(i=0;i<nums1.size();i++) {
        l1 = new ListNode(nums1[i], l1);
    }
    for(i=0;i<nums2.size();i++) {
        l2 = new ListNode(nums2[i], l2);
    }
	Solution solution;
	ListNode *p = solution.addTwoNumbers(l1, l2);
	//ListNode *p = solution.reverseList(l1);
    //ListNode *p = l1;
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }
	return 0;
}



