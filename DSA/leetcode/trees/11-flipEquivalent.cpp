//LC 951

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //just like the sameTree you check curr roots if equal or not
        //if not equal -> return false
        //if equal -> continue checking deeper for flip equiv
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr || root2 == nullptr) return false;
        if(root1->val != root2->val) return false;

        //if both root val are equal you check left and right
        bool l = flipEquiv(root1->left, root2->left);
        bool r = flipEquiv(root1->right, root2->right);
        if(l== true && r == true) return true;

        //if any one of the l or r isn't equiv 
        //you swap the params in teh flipEquiv and check 
        bool flippedL = flipEquiv(root1->left, root2->right);
        bool flippedR = flipEquiv(root1->right, root2->left);
        if(flippedL == true && flippedR == true) return true;
        
        return false;
        

    }

};