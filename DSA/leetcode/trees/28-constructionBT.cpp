
 // PREORDER AND INORDER

class Solution {
public:
    unordered_map<int,int> indexInorder; //stores index of each elem in inorder for finding root inorder and splititng left and right subtree
    int idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            indexInorder[inorder[i]] = i;
        }
        TreeNode* ans = func(preorder, 0, inorder.size()- 1);
        return ans;
    }  

    TreeNode* func(vector<int>& preorder, int low, int high){
        if(low > high) return nullptr; 
        TreeNode* node = new TreeNode(preorder[idx]); //curr idx
        idx++;
        int id = indexInorder[node->val];
        node->left = func(preorder, low, id-1); //everything before the node in inorder is left subtree
        node->right = func(preorder, id + 1, high);
        return node;

    }
};

//POSTORDER AND INORDER
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
    unordered_map<int,int> indexInorder; //stores index of each elem in inorder for finding root inorder and splititng left and right subtree
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        for(int i = 0; i < inorder.size(); i++){
            indexInorder[inorder[i]] = i;
        }
        TreeNode* ans = func(postorder, 0, inorder.size()-1, idx);
        return ans;
    }  

    TreeNode* func(vector<int>& postorder, int low, int high, int& idx){
        if(low > high || idx < 0) return nullptr; 
        TreeNode* node = new TreeNode(postorder[idx]); //curr idx
        idx--;
        int id = indexInorder[node->val];
        //order change as postorder = left right root so go reverse
        node->right = func(postorder, id + 1, high,idx);
        node->left = func(postorder, low, id-1,idx); //everything before the node in inorder is left subtree
        return node;
    }

};