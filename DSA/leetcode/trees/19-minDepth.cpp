// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            return 1; //leaf
        }
        if(root->left == nullptr){
            return 1 + minDepth(root->right);
        }
        if(root->right == nullptr){
            return 1 + minDepth(root->left);
        }

        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};