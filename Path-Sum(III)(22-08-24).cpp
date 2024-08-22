class Solution {
public:
    void solve(int &count,TreeNode* root,long long targetSum){
        if(root==NULL){
            return;
        }
        
        if((long long)(root->val)==targetSum){
           count++;
        }
        
            solve(count,root->left,targetSum-(long long)(root->val));
            solve(count,root->right,targetSum-(long long)(root->val));
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }

        int count=0;

        solve(count,root,(long long)targetSum);

        count+=pathSum(root->left,targetSum)+pathSum(root->right,targetSum);

        return count;
    }
};
