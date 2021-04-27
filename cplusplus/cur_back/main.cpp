#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stdlib.h>
#include <deque>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class treeTool {
public:
    TreeNode *createTree(vector<string>& nums) {
        static int index=-1;
        index++;
        //cout << nums.size() << "\t" << index << endl; 
        if(nums.size() <= index || nums[index] == "null")
            return NULL;
        TreeNode * root = new TreeNode(atoi(nums[index].c_str()));
        root->left = createTree(nums);
        root->right = createTree(nums);
        return root;
    }
    void firstList(TreeNode *root, vector<int>& res) {
        if(root == NULL)
            return ;
        res.push_back(root->val);
        firstList(root->left, res);
        firstList(root->right, res);
    }
    void midList(TreeNode *root, vector<int>& res) {
        if(root == NULL)
            return ;
        midList(root->left, res);
        res.push_back(root->val);
        midList(root->right, res);
    }
    void tailList(TreeNode *root, vector<int>& res) {
        if(root == NULL)
            return ;
        tailList(root->left, res);
        tailList(root->right, res);
        res.push_back(root->val);
    }
    void stepList(TreeNode* root, vector<vector<int>>& res) {
        if(root == NULL) return;
        int size,i;
        TreeNode * node;
        deque<TreeNode*> que;
        que.push_back(root);
        //vector<vector<int>> res;
        while(que.size()) {
            vector<int> curv;
            size = que.size();
            for(i=0;i<size;i++) {
                node = que.front();
                curv.push_back(node->val);
                que.pop_front();
                if(node->left != NULL)
                    que.push_back(node->left);
                if(node->right != NULL)
                    que.push_back(node->right);
            }
            res.push_back(curv);
        }
    }

};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        treeTool trt;
        trt.stepList(root, res);
        return res;
    }
};

int main(int argc, char ** argv) {
    vector<string> nums;
    int i, j;
    for(i=1;i<argc;i++)
        nums.push_back(argv[i]);
    treeTool trt;
    TreeNode *root =  trt.createTree(nums);
    //cout << "ok" << endl;
    Solution solution;
    vector<vector<int>> res = solution.levelOrder(root);
    for(i=0;i<res.size();i++) {
        for(j=0;j<res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
