class Solution {
public:
    TreeNode* construct(int postStart,int postEnd,int &preIndex,vector<int>& preorder, vector<int>& postorder){
        if(postStart>postEnd){
            return NULL;
        }

        TreeNode* node=new TreeNode(preorder[preIndex]);
        preIndex++;
        if(postStart==postEnd){
            return node;
        }
        auto it=find(postorder.begin(),postorder.end(),preorder[preIndex]);
        int postIndex=it-postorder.begin();

        node->left=construct(postStart,postIndex,preIndex,preorder,postorder);
        node->right=construct(postIndex+1,postEnd-1,preIndex,preorder,postorder);

        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex=0;
        return construct(0,preorder.size()-1,preIndex,preorder,postorder);
    }
};
