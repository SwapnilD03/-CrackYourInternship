class Solution {
public:
    void getInorder(TreeNode* root,vector<int>&inorder){
        if(root==NULL){
            return;
        }

        getInorder(root->left,inorder);
        inorder.push_back(root->val);
        getInorder(root->right,inorder);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        getInorder(root,inorder);
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1]){
                return false;
            }
        }

        return true;
    }
};
