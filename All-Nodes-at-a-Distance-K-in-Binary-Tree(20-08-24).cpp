class Solution {
public:
    void getParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
       
        while(!q.empty()){
            
            TreeNode* front=q.front();
            q.pop();

            if(front->left){
                q.push(front->left);
                parent[front->left]=front;
            }

            if(front->right){
                q.push(front->right);
                parent[front->right]=front;
            }
            }
        
    }
            
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,bool> visited;
        unordered_map<TreeNode*,TreeNode*> parent;
        getParents(root,parent,target);
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;

        int curr_lvl=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_lvl++ == k) break;
            for(int i=0;i<size;i++){
            TreeNode* front=q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                q.push(front->left);
                visited[front->left]=true;
            }

            if(front->right && !visited[front->right]){
                q.push(front->right);
                visited[front->right]=true;
            }
            if(parent[front] && !visited[parent[front]]){
                q.push(parent[front]);
                visited[parent[front]]=true;
            }
            }
        }

        while(!q.empty()){
            TreeNode* curr=q.front();q.pop();
            ans.push_back(curr->val);
        }

        return ans;

    }
};
