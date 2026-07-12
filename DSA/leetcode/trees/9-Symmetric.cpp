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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        bool ans =  isSameTree(root->left, invertTree(root->right));
        return ans;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr & q == nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr){
            return false;
        }
        
        if(p->val != q-> val) return false;

        bool l = isSameTree(p->left,q->left);
        bool r = isSameTree(p->right,q->right);
        
        if(l == true && r == true){
            return true;
        }
        return false;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* newRightL = root->left;
        TreeNode* newLeftR = root->right;
        root->left = newLeftR;
        root->right = newRightL;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};z