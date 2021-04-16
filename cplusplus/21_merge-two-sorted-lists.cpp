#include <iostream>
#include <vector>
#include <string>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *p = head;
        while(l1 || l2) {
            if(!l1) {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
                continue;
            }
            else if(!l2) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
                continue;
            }
            if(l1->val>l2->val) {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
            else {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
        }
        p = head->next;
        delete head;
        return p;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!(l1||l2))
            return NULL;
        if (!l1) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        if (!l2) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        return NULL;
    }
};




//TODO:优化方法，当某一个链表为空时，不用再递归或者迭代了，直接将另一个非空链表放在next处即可

int main(int argc, char ** argv) {
	ListNode * l1 = new ListNode(18);
	ListNode * l2 = new ListNode(18);
	int i;
	for(i=8;i>=0;i--) {
       l1 =  new ListNode(i*2, l1);
       l2 =  new ListNode(i*2+1, l2);
    }
	Solution2 solution;
	ListNode *m = solution.mergeTwoLists(l1, NULL);
	//ListNode *m = l2;
    while(m) {
        cout << m->val << endl;
        m = m->next;
    }
	return 0;
}
