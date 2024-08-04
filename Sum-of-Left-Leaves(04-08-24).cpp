class Solution {
public:
    void Helper(TreeNode* root,bool is_leftNode,int&ans){
        if(root==NULL){
            return;
        }

        if(root->left == NULL && root->right==NULL && is_leftNode){
            ans+=root->val;
        }

        Helper(root->left,true,ans);
        Helper(root->right,false,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool is_leftNode=false;

        int ans=0;
        Helper(root,is_leftNode,ans);
        return ans;
    }
};
