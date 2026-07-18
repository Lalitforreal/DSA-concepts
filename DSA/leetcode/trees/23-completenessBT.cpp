//Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last,
// is completely filled, and all nodes in the last level are as far left as possible.
// It can have between 1 and 2h nodes inclusive at the last level h.

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        //curr is null then no node after it should exist then only complete
        q.push(root);
        bool isNull = false;
        vector<vector<TreeNode*>> res;
        while(!q.empty()){
            int lvlSize = q.size();
            vector<TreeNode*> temp(lvlSize);
            while(lvlSize > 0){
                TreeNode* curr = q.front();
                if(isNull == true && curr!= nullptr) return false;
                    q.pop();
                    temp.push_back(curr);
                    lvlSize--;
                if(curr == nullptr){
                    isNull = true;
                    continue;
                }
                //push even if null
                q.push(curr->left);
                q.push(curr->right);
            }
            res.push_back(temp);
        }
        return true;
    }

};