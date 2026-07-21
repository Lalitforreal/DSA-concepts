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
//find mid of nums,
//build left 
//build right
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1 ;
        int mid = (high + low)/2;
        TreeNode* ans = helper(nums, low, high, mid);
        return ans;

    }
    TreeNode* helper(vector<int>& nums, int low, int high, int mid) {
        mid = (high + low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (root == nullptr || low > high) return nullptr;

        root->left = helper(nums, low, mid -1, mid);
        root->right = helper(nums, mid+1, high, mid);

        return root;
    }

};