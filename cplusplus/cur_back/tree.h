#include <string>
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

};

