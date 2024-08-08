class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode=new ListNode(0);
        dummyNode->next=head;

        ListNode* leftPrev=dummyNode;
        ListNode* curr=head;

        for(int i=0;i<left-1;i++){
            leftPrev=curr;
            curr=curr->next;
        }

        ListNode* prev=NULL;
        for(int i=0;i<right-left+1;i++){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        leftPrev->next->next=curr;

        leftPrev->next=prev;
        return dummyNode->next;
    }
};
