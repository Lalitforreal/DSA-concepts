
//  Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
//LC 230

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        solve(root,count,ans,k);
        return ans;

    }

    void solve(TreeNode* root, int& count , int &ans , int k){
        if(root == nullptr) return;
        solve(root->left, count, ans, k);
        count++;
        if(count == k){
            ans = root->val;
        }
        solve(root->right, count, ans, k);
        return;

    }
};