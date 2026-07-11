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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);

        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> temp;
            while(lvlSize>0){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                lvlSize--;

                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};



//level order II
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);

        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> temp;
            while(lvlSize>0){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                lvlSize--;

                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//zigzag traversal
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);
        bool zigZag = false;
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> temp;
            while(lvlSize>0){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                lvlSize--;
                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);

            } 
            if(zigZag == true){
                reverse(temp.begin(),temp.end());
            }
            zigZag = !zigZag;
            ans.push_back(temp);
        }
        return ans;
    }
};