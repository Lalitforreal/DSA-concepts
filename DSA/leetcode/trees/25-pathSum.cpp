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
    bool res = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        dfs(root, sum, targetSum);
        return res;
    }

    void dfs(TreeNode* root, int sum, int targetSum){
        if(root == nullptr) return;
        sum+= root->val;

        // leaf node
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                res = true;
            }
            return;
        }
        //not leaf -> recurse
        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
        return;
    }
};