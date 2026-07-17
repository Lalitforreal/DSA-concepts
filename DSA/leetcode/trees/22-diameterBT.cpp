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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        if(root == nullptr) return 0;
        int curr = longestPath(root);
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);


        return max(curr, max(left,right));

    }
    int longestPath(TreeNode* root){
        if(root == nullptr) return 0;
        return heightSt(root->left) + heightSt(root->right);
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