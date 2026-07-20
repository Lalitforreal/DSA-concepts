
class Solution {
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }

    //updates the global var in the end before returning
    int helper(TreeNode* root){
        if(root == nullptr) return 0;

        int left = max(0,helper(root->left));
        int right = max(0,helper(root->right));

        ans = max(ans, left + right + root->val); //a whole subtree (^) alll three nodes/subtree
        int final = root->val + max(left, right); //return the max val of the path below to teh upper node
        return final;
    }
};