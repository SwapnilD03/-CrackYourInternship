class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int> > > nodes;

        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> p=q.front();
            q.pop();
            TreeNode* frontNode=p.first;
            int hd=p.second.first;
            int lvl=p.second.second;
            nodes[hd][lvl].push_back(frontNode->val);
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }

        for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                sort(j.second.begin(), j.second.end());
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }

        return ans;

    }
};
