class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }

         queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            ans.push_back(q.back()->val);
            for(int i=0;i<size;i++){
                TreeNode* frontNode=q.front();
                q.pop();

                if(frontNode->left){
                    q.push(frontNode->left);
                }

                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }

            
        }

        return ans;
    }
};
