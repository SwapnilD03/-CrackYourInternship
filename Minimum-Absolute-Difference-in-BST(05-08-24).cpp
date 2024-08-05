class Solution {
public:

    void getInorder(vector<int>& inorder,TreeNode* root){
        if(root==NULL){
            return;
        }

        getInorder(inorder,root->left);
        inorder.push_back(root->val);
        getInorder(inorder,root->right); 
   }

    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;

        getInorder(inorder,root);

        int minDiff=INT_MAX;
        for(int i=0;i<inorder.size()-1;i++){
            minDiff=min(minDiff,inorder[i+1]-inorder[i]);
        }

        return minDiff;
    }
};
