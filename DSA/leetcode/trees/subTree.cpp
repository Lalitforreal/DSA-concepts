//LC 572

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr || subRoot == nullptr) return false;

        if(root-> val == subRoot->val ){
            bool sameVal = isSameTree(root, subRoot);
            if(sameVal == true)return true;
        }


        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);


        if(l == true || r == true) return true; //if any one true
        return false;
    }

    bool isSameTree(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr) return true;

        if(root1 == nullptr || root2 == nullptr) return false;
        if(root1->val != root2->val) return false;

        bool l = isSameTree(root1->left, root2->left);
        bool r = isSameTree(root1->right, root2->right);

        if(l == true && r == true) return true;
        return false;
    }
};