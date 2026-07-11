

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //root 1 and 2 check if
        // both null -> correct
        // boht arent saem -> false
        // value aren't same ->false
        //recursively call left and right
        if(p == nullptr & q == nullptr){
            return true;
        }
        //
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
};