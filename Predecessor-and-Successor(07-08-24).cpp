class Solution
{
    public:
    void getInorder(Node* root,vector<Node*>&inorder){
        if(root==NULL){
            return;
        }
        
        getInorder(root->left,inorder);
        inorder.push_back(root);
        getInorder(root->right,inorder);
        
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        vector<Node*> inorder;
        getInorder(root,inorder);
        pre=NULL;suc=NULL;
        
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]->key<key){
                pre=inorder[i];
            }
        }
        
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]->key>key){
                suc=inorder[i];break;
            }
        }
        
    }
};
