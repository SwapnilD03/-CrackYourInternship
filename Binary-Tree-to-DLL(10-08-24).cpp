class Solution {
  public:
    void getInorder(Node* root,vector<Node*> &inorder){
        if(root==NULL){
            return;
        }
        
        getInorder(root->left,inorder);
        inorder.push_back(root);
        getInorder(root->right,inorder);
    }
    
    Node* bToDLL(Node* root) {
        vector<Node*> inorder;
        getInorder(root,inorder);
        Node* curr=inorder[0];
        Node* head=curr;
        Node* prev=NULL;
        
        for(int i=0;i<inorder.size()-1;i++){
            curr->left=prev;
            curr->right=inorder[i+1];
            
            curr=curr->right;
            prev=inorder[i];
        }
        
        curr->left=prev;
        curr->right=NULL;
        
        return head;
        
    }
};
