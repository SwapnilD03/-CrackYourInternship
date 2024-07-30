class Solution {
public:
    void TraverseInorder(TreeNode* root,vector<int>&inorder){
        if(root==NULL){
            return;
        }

        TraverseInorder(root->left,inorder);
        inorder.push_back(root->val);
        TraverseInorder(root->right,inorder);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TraverseInorder(root,inorder);
        return inorder;
    }
};
