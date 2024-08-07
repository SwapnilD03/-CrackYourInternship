class Solution {
  public:
    Node* merge(Node* a,Node * b){
        if(a==NULL && b==NULL){
            return NULL;
        }
        if(a==NULL && b!=NULL){
            return b;
        }
        if(a!=NULL && b==NULL){
            return a;
        }
        Node* temp=new Node(-1);
        Node* curr=temp;
        while(a!=NULL && b!=NULL){
            if(a->data<b->data){
                curr->bottom=a;
                curr=curr->bottom;
                a=a->bottom;
            }
            else{
                curr->bottom=b;
                curr=curr->bottom;
                b=b->bottom;
            }
        }
        
        if(a!=NULL){
            curr->bottom=a;
        }
        else{
            curr->bottom=b;
        }
        
        return temp->bottom;
    }
    Node *flatten(Node *root) {
        if(root==NULL){
            return NULL;
        }
        if(root->next==NULL){
            return root;
        }
        
        root->next=flatten(root->next);
        root=merge(root,root->next);
        
        return root;
    }
};
