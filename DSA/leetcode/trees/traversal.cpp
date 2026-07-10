/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderT(root, ans);
        return ans;

    }

    void inorderT(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        inorderT(root->left,ans);
        ans.push_back(root->val);
        inorderT(root->right,ans);
        return;
    }

    void preT(TreeNode* root, vector<int>& ans ){
        if(root == nullptr) return;

        ans.push_back(root->val);
        preT(root->left, ans);
        preT(root->right, ans);
        return;

    }

    void postorderT(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        postorderT(root->left,ans);
        postorderT(root->right,ans);
        ans.push_back(root->val);
        return;
    }
};