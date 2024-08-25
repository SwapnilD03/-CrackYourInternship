class Solution {
public:
    vector<TreeNode*> generate(int left,int right){
        if(left>right){
            return {NULL};
        }
        vector<TreeNode*>ans;

        for(int i=left;i<=right;i++){
           TreeNode* root=new TreeNode(i);
           for(auto leftTree:generate(left,i-1)){
            for(auto rightTree:generate(i+1,right)){
                TreeNode* root=new TreeNode(i,leftTree,rightTree);
                ans.push_back(root);
            }
           } 
        }

        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
};
