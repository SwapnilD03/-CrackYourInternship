class Solution {
public:
    void traverseInorder(TreeNode* root,vector<int>& inorder){
        if(root==NULL)
        return;

        traverseInorder(root->left,inorder);
        inorder.push_back(root->val);
        traverseInorder(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
      vector<int> inorder;
      traverseInorder(root,inorder);
      return inorder[k-1];
    }
};
