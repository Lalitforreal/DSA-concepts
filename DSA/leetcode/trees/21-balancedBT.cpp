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
    bool isBalanced(TreeNode* root) {
        //diff of (left subtree heigh - right subtree height) <= 1
        if(root == nullptr) return true;
        if(abs(heightSt(root->left) - heightSt(root->right)) > 1){
            return false;
        }
        bool rootL = isBalanced(root->left);
        bool rootR = isBalanced(root->right);
        if(rootL && rootR){
            return true;
        }
        return false;

    }
    int heightSt(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr ){
            return 1;
        }
        if(root-> left == nullptr){
            return 1 + heightSt(root->right);
        }
        if(root-> right == nullptr){
            return 1+ heightSt(root->left);
        }
        return 1 + max(heightSt(root->left), heightSt(root->right));
    }
    
};