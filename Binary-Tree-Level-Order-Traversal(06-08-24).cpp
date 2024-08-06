class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int l=q.size();
            vector<int> res;
            for(int i=0;i<l;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL){
                   q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                res.push_back(node->val);
            }               
                ans.push_back(res);      
        }
        return ans;
    }
};
