/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        int total = LCS(root, p,q, ans);
        return ans; //passes by ref
    }
    int LCS(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& ans ){
        if(root == nullptr) return 0;

        int left = LCS(root->left, p, q, ans);
        int right = LCS(root->right, p, q, ans);
        int self = 0;
        if(root == p || root == q) self = 1;
        int total = left + right + self;
        if(total == 2 && ans == nullptr){ //only the first occ of 2 child is the lowest
            ans = root;
        }
        return total;
    }
};