class Solution {
public:
    ListNode* getKth(ListNode* curr,int k){
        while(curr!=NULL && k>0){
            curr=curr->next;
            k--;
        }

        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* groupPrev=dummy;

        while(true){
           ListNode* kthNode=getKth(groupPrev,k);
           if(kthNode==NULL){
            break;
           }
           ListNode* groupNext=kthNode->next;

           ListNode* prev=kthNode->next;
           ListNode* curr=groupPrev->next;

           while(curr!=groupNext){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
           }
           ListNode* node=groupPrev->next;
           groupPrev->next=kthNode;
           groupPrev=node;
        }
        return dummy->next;
    }
};
