class Solution{
  public:
  
    bool check(Node *root,int low,int high){
      if(root==NULL){
          return false;
        }
      if(root->left==NULL && root->right==NULL){
           if(root->data - low ==1 && high-root->data==1)
              return true;
           else
              return false;
      }
      
      bool left=check(root->left,low,root->data);
      bool right=check(root->right,root->data,high);
      
      return left||right;
   }
    bool isDeadEnd(Node *root)
    {
        return check(root,0,INT_MAX);
        
    }
};
