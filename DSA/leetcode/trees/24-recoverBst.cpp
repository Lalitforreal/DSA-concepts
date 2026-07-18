
//LC-99
// You are given the root of a binary search tree (BST),
//  where the values of exactly two nodes of the tree were swapped by mistake.
//   Recover the tree without changing its structure.




class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }

    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root->left);
        if(prev && prev->val > root->val){
            if(!first) first = prev; //one time only 
            second = root; //will change when backtracked
        }
        prev = root;
        inorder(root->right);
    }
};