class Solution
{
    public:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL){
            Node* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        head=reverse(head);
        
        Node* curr=head;
        int maxi=head->data;
        Node* prev=head;
        head=head->next;
        
        while(head!=NULL){
            if(head->data>=maxi){
                maxi=head->data;
                prev=head;
                head=head->next;
            }
            else{
                prev->next=head->next;
                head=head->next;
            }
        }
        
        head=reverse(curr);
        return head;
    }
    
};
   
