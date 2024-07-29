class Solution {
public:
    pair<int,int> diameterHelper(TreeNode* root){
         if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
         }

         pair<int,int> left=diameterHelper(root->left);
         pair<int,int> right=diameterHelper(root->right);

         int ans1=left.first;
         int ans2=right.first;

         int ans3=left.second+right.second;

         pair<int,int> ans;
         ans.first=max(ans1,max(ans2,ans3));
         ans.second=max(left.second,right.second)+1;
         return ans;



    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> res=diameterHelper(root);
        return res.first;
    }
};
