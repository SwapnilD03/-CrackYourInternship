class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        ll maxi=0;
        queue<pair<TreeNode*,ll>> q;

        q.push(make_pair(root,0));

        while(!q.empty()){
           int size=q.size();
           ll frontIdx=q.front().second;
           ll lastIdx=q.back().second;
           maxi=max(maxi,lastIdx-frontIdx+1);
           for(int i=0;i<size;i++){
            TreeNode* node=q.front().first;
            ll idx=q.front().second;
            q.pop();
            if(node->left){
                q.push(make_pair(node->left,idx*2+1));
            }
            if(node->right){
                q.push(make_pair(node->right,idx*2+2));
            }
           }
        }
        return maxi;
    }
};
