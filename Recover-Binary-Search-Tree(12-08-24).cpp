class Solution {
    private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* second;
    private:
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }

        inorder(root->left);

        if(prev!=NULL && (root->val < prev ->val)){
            if(first==NULL){
            first=prev;
            middle=root;
            }
        else{
            second=root;
        }
        }

        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=middle=second=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first!=NULL && second!=NULL){
            swap(first->val,second->val);
        }
        else if(first!=NULL && middle!=NULL){
            swap(first->val,middle->val);        
        }
    }
};
