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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, long long>> q; //q<node, s.no of curr>
        // to find idx -> 2 * (end - start + 1) + 1
        
        long long res = 1;

        q.push({root,0});
        while(!q.empty()){
            long long start = q.front().second;
            long long end = q.back().second;
            int size = q.size();

            res = max(res, end- start + 1);
            while(size > 0){
                pair<TreeNode*, long long> p = q.front();
                TreeNode* node = p.first;
                q.pop();
                size--;
                long long idx = p.second - start;
                if(node->left != NULL){
                    q.push({node->left, (long long) 2 * idx + 1});
                }
                if(node->right != NULL){
                    q.push({node->right, (long long) 2 * idx + 2});
                }
            }
        }
        return res;
    }
};