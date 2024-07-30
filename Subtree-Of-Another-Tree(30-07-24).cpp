class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL)
            return true;
        if(root==NULL)
            return false;
        if(isEqual(root,subRoot))
            return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

    bool isEqual(TreeNode* r1, TreeNode* r2){
        if(r1==NULL && r2==NULL)
            return true;
        if(r1==NULL || r2==NULL)
            return false;
        if(r1->val!=r2->val)
            return false;
        return isEqual(r1->left,r2->left) && isEqual(r1->right,r2->right);
    }
};
