//LC - 98
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return false;
        stack<TreeNode*> st;
        TreeNode* p = root;
        TreeNode* prev = nullptr;
        while(p){
            st.push(p);
            p = p->left;
        }

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            //process curr

            if(prev != nullptr && curr->val <= prev->val){
                return false;
            }

            TreeNode* right = curr->right;
            while(right){
                st.push(right);
                right = right->left;
            }
            prev = curr;
        }
        return true;

    }
};