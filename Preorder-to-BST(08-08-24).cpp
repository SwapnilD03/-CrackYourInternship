class Solution {
  public:
    Node* dfs(int pre[],int &i,int size,int bound){
            if(i==size || pre[i]>bound){
                return NULL;
            }        
            
            Node* root=newNode(pre[i]);
            i++;
            root->left = dfs(pre,i,size,root->data);
            root->right=dfs(pre,i,size,bound);
            
            return root;
    }
    Node* Bst(int pre[], int size) {
        int i=0;
        return dfs(pre,i,size,INT_MAX);
    }
};
