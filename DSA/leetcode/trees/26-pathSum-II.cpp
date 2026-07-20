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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        fun(root, sum,ans,temp, targetSum);
        return ans;
    }

    void fun(TreeNode* root,int sum, vector<vector<int>>& ans, vector<int> temp,int targetSum){
        if(root == nullptr) return;

        sum += root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right){
            if(sum == targetSum){
                ans.push_back(temp);
            }
            return;
        }

        fun(root->left, sum, ans, temp,targetSum);
        fun(root->right, sum, ans, temp,targetSum);
        return;
    }
};