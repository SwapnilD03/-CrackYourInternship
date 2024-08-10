class Solution {
public:
    void getPreorder(TreeNode* root,vector<TreeNode*> &preorder){
        if(root==NULL){
            return;
        }
        preorder.push_back(root);
        getPreorder(root->left,preorder);
        getPreorder(root->right,preorder);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> preorder;
        getPreorder(root,preorder);
        TreeNode* head=new TreeNode(0);
        TreeNode* curr=head;

        for(int i=0;i<preorder.size();i++){
            curr->right=preorder[i];
            curr->left=NULL;
            curr=curr->right;
        }

        head=head->right;

    }
};
