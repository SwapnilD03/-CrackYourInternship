class Solution {
public:
    // Three states :  0 --> Not covered   1 --> Covered by Camera  2 --> Camera
    int cams=0;
    int dfs(TreeNode* node){
        if(node==NULL) return 1;
        int left=dfs(node->left);
        int right=dfs(node->right);

        if(left==0 || right == 0){
            cams++;
            return 2;
        }
        else if(left==2 || right ==2 )
        return 1;
        
        else 
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int ans=dfs(root);
        return (ans==0)?cams+1:cams;
    }
};
