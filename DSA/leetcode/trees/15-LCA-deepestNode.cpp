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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode*> ans = helper(root);
        return ans.second;
    }

    pair<int, TreeNode*> helper(TreeNode* root){
        if(root == nullptr) return {-1, nullptr};

        pair<int, TreeNode*> left = helper(root->left);
        pair<int, TreeNode*> right = helper(root->right);
        if(left.first > right.first){
            return {left.first+1, left.second};

        }
        if(left.first < right.first){
            return {right.first+1, right.second};
        }
        //equal
        return {left.first+1, root}; //return root itself as it is the lca

    }
};