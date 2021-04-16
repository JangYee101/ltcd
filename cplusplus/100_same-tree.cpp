#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int g_index;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode * _initTree(vector<int> &nums) {
    if(g_index+1 > nums.size()) {
        exit(123);
    }
    if(nums[g_index] == 0) {
        g_index++;
        return NULL;
    }
    TreeNode *root =  new TreeNode(nums[g_index++]);
    root->left = _initTree(nums);
    root->right = _initTree(nums);
    return root;
}

TreeNode * initTree(vector<int> &nums) {
    g_index = 0;
    return _initTree(nums);
}

void preShowNode(TreeNode * head) {
    if(!head) return ;
    cout << head->val << endl;
    preShowNode(head->left);
    preShowNode(head->right);
}


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!(p||q))
            return true;
        if(!(p&&q))
            return false;
        if(p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


int main(int argc, char ** argv) {
    int i;
    vector<int> nums1={1,2,0,0,3,0,0}, nums2 = {1,2,0,0,2,0,0};
    //vector<int> nums1={1,0,0}, nums2 = {2,0,0};
    TreeNode *t1 = initTree(nums1), *t2 = initTree(nums2);
	Solution solution;
    preShowNode(t1);
    preShowNode(t2);
	cout << "-----------\n"  << solution.isSameTree(t1, t2) << endl;
	return 0;
}



