#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeTool {
public:
	TreeNode * createTree(vector<string> &nums) {
        static int index = -1;
        index++;
        int size = nums.size();
        if(index >= size || nums[index] == "null")
            return NULL;
        TreeNode * root = new TreeNode(atoi(nums[index].c_str()));
        root->left = createTree(nums);
        root->right = createTree(nums);
        return root;
    }

    TreeNode* createLTree(vector<string> & nums) {
        int csize=1, size = nums.size(), preI;
        deque<TreeNode*> que;
        if(size == 0)
            return NULL;
        TreeNode * root = new TreeNode(atoi(nums[0].c_str())), *left, *right, *father;
        que.push_back(root);
        for(int i=1;i<size;i=i+csize) {
            for(int j=0;j<csize;j++) {
                preI =  i+2*j;
                father = que.front();
                if(nums[preI] != "null") {
                    left = new TreeNode(atoi(nums[preI].c_str()));
                    father->left = left;
                    que.push_back(left);
                }
                if(nums[preI+1] != "null") {
                    right = new TreeNode(atoi(nums[preI+1].c_str()));
                    father->right = right;
                    que.push_back(right);
                }
                que.pop_front();
            }
            csize *= 2;
        }
        return root;
    }

    void _preList(TreeNode *root) {
        if(!root) {
            cout << "null" << endl;
            return ;
        }
        cout << root->val << endl;
        _preList(root->left);
        _preList(root->right);
    }

    void preList(TreeNode* root) {
        cout << "pre List start" << endl;
        _preList(root);
        cout << "pre List end" << endl;
    }

    void levelList(TreeNode *root, vector<vector<int>>& res) {
        if(root == NULL)
            return ;
        int size, i;
        TreeNode* node;
        deque<TreeNode*> que;
        que.push_back(root);
        while(!que.empty()) {
            vector<int> curv;
            size = que.size();
            for(i=0;i<size;i++) {
                node = que.front();
                que.pop_front();
                curv.push_back(node->val);
                if(node->left)
                    que.push_back(node->left);
                if(node->right)
                    que.push_back(node->right);
            }
            res.push_back(curv);
        }
    }
	
};

class Solution {
public:
    bool comm(TreeNode * left, TreeNode *right) {
        if(!(left || right))
            return true;
        if(!left || !right)
            return false;
        if(left->val != right->val)
            return false;
        return comm(left->left, right->right) && comm(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return comm(root->left, root->right);
    }
};



int main(int argc, char ** argv) {
    vector<string> s1;
    int i, j;
    for(i=1; i<argc; i++)
        s1.push_back(argv[i]);
    TreeTool trt;
    TreeNode * root = trt.createLTree(s1);
    trt.preList(root);
    Solution solution;
    cout <<  solution.isSymmetric(root) << endl;
	return 0;
}











