class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k=0;
        ListNode* curr=head;
        while(curr!=0){
            k++;
            curr=curr->next;
        }
        if(n==k){
            head=head->next;
            return head;
        }
        int pos=0;
        curr=head;
        ListNode* prev=NULL;
        while(pos<k-n){
            prev=curr;
            curr=curr->next;
            pos++;
        }
        prev->next=curr->next;
        return head;
    }
};
