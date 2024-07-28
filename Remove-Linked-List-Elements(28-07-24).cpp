class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }

        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val==val){
                if(curr==head){
                    head=head->next;
                }
                else{
                    prev->next=curr->next;
                }
            }
            else{
            prev=curr;
            }
            curr=curr->next;
        }
        if(prev==NULL){
            return NULL;
        }
        return head;
    }
};
