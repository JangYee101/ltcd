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

    string _numsAt(vector<string>& nums, int index) {
        if(nums.size()<=index)
            return "null";
        return nums[index];
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
                if(_numsAt(nums, preI) != "null") {
                    left = new TreeNode(atoi(nums[preI].c_str()));
                    father->left = left;
                    que.push_back(left);
                }
                if(_numsAt(nums, preI+1) != "null") {
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
    static int sum;
    static bool find;
    void initStaticVal() {
        sum = 0;
        find = false;
    }
    bool _hasPathSum(TreeNode* root, int targetSum) {
        if(find) return true;
        if(root == NULL) return false;
        sum += root->val;
        if(!root->left && !root->right) {
            if(sum == targetSum) return true;
            //sum -= root->val;
        }
        if(root->left) {
            find = _hasPathSum(root->left, targetSum);
            sum -= root->left->val;
        }
        if(root->right) {
            find = _hasPathSum(root->right, targetSum);
            sum -= root->right->val;
        }
        return find;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        initStaticVal();
        return _hasPathSum(root, targetSum);
    }
};

int Solution::sum = 0;
bool Solution::find = false;

int main(int argc, char ** argv) {
    vector<string> s1;
    int i, j;
    for(i=1; i<argc; i++)
        s1.push_back(argv[i]);
    TreeTool trt;
    TreeNode * root = trt.createLTree(s1);
    //trt.preList(root);
    Solution solution;
    //cout << solution.hasPathSum(root, 1) << endl;
    //cout << solution.hasPathSum(root, 2) << endl;
    //cout << solution.hasPathSum(root, 3) << endl;
    //cout << solution.hasPathSum(root, 5) << endl;
    cout << solution.hasPathSum(root,22) << endl;
	return 0;
}









