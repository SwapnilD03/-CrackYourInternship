class Solution {
  public:
    Node* zigZag(Node* head) {
        Node* curr=head;
        int f=0;
        while(curr->next!=NULL){
            if(f==0){
                if(curr->data> curr->next->data){
                    swap(curr->data,curr->next->data);
                }
            }
            
            else{
                if(curr->data < curr->next->data){
                    swap(curr->data,curr->next->data);
                }
            }
            f=!f;
            curr=curr->next;
        }
        return head;
    }
};
