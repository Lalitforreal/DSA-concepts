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
    vector<int> temp;
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int res = 0;
        fun(root, sum);
        for(int i = 0; i < temp.size(); i++){
            cout<<temp[i];
            res += temp[i];
        }
        return res;
    }

    void fun(TreeNode* root,int sum){
        if(root == nullptr) return;

        sum = sum * 10 + root->val;

        if(!root->left && !root->right){
            temp.push_back(sum);
            return;
        }

        fun(root->left, sum);
        fun(root->right, sum);
        return;
    }
};