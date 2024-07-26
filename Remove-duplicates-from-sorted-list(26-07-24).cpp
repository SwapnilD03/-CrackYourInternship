class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }

        if(head->next==NULL){
            return head;
        }
      
        ListNode* curr=head;

        ListNode* nextNode=head->next;

        while(nextNode!=NULL){
            if(nextNode->val!=curr->val){
                curr->next=nextNode;
                curr=nextNode;
            }
            nextNode=nextNode->next;
        }
        curr->next=NULL;
        return head;

    }
};
