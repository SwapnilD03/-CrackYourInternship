class Solution {
public:
    void inorderTraversal(TreeNode* root,vector<int> &inorder){
        if(root==NULL){
            return;
        }

        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
        int sum=0;
        for(int i=0;i<inorder.size();i++){
           if(inorder[i]>=low && inorder[i]<=high)
           sum+=inorder[i];
        }
        return sum;
    }
};
