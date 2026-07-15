//TWO SUM - IV


class Solution {
public:
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr){
            return false;
        }
        TreeNode* p = root;
        while(p){
            asc.push(p);
            p = p->left;
        }
        p = root;
        while(p){
            desc.push(p);
            p = p->right;
        }

        TreeNode* i = getSmall();
        TreeNode* j = getBig();
        while(  i && j && i!=j && i->val < j ->val){
            int sum = i-> val + j-> val;
            if(sum == k){
                return true;
            }else if(sum > k){
                j = getBig(); //dec
            }else{
                i = getSmall(); //inc
            }
        }
        return false;
    }
    TreeNode* getSmall(){
        if(asc.empty()){
            return nullptr;
        }
        TreeNode* small = asc.top();
        asc.pop();
        //right and uske left ke saare push 
        TreeNode* rightChild = small->right;
        while(rightChild){
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;
    }
    TreeNode* getBig(){
        if(desc.empty()){
            return nullptr;
        }
        TreeNode* big = desc.top();
        desc.pop();
        //right and uske left ke saare push 
        TreeNode* leftChild = big->left;
        while(leftChild){
            desc.push(leftChild);
            leftChild = leftChild->right;
        }
        return big;
    }
};