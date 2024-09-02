class Solution {
  public:
    int length(Node* node){
        int size=0;
        while(node!=NULL){
            size++;node=node->next;
        }
        return size;
    }
    Node *reverse (Node* head){
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        while(head1 && head1->data==0){
            head1=head1->next;
        }
        while(head2 && head2->data==0){
            head2=head2->next;
        }
        
        int n1=length(head1);
        int n2=length(head2);
        
        if(n2>n1) swap(head1,head2);
        
        if(n1==n2){
            Node* l1=head1,*l2=head2;
            while(l1->data == l2->data){
                l1=l1->next;
                l2=l2->next;
                
                if(!l1) return new Node(0);
            }
            
            if(l2->data>l1->data) swap(head1,head2);
        }
        
        head1=reverse(head1);
        head2=reverse(head2);
        
        Node* res=NULL;
        Node* l1=head1,*l2=head2;
        while(l1){
            
            int small=0;
            if(l2) small=l2->data;
            
            if(l1->data<small){
                l1->next->data=l1->next->data-1;
                l1->data=l1->data+10;
            }
            
            Node* n=new Node(l1->data-small);
            
            n->next=res;
            res=n;
            
            l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        
        while(res->next!=NULL && res->data==0){
            res=res->next;
        }
        
        return res;
        
    }
};
