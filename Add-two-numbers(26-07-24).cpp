class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode(0);
        ListNode* head=l3;
        int carry=0;
        while(l1 && l2){
            int val=l1->val + l2->val +carry;
            int d=val%10;
            carry=val/10;
            l3->next=new ListNode(d);
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int val=l1->val +carry;
            int d=val%10;
            carry=val/10;
            l3->next=new ListNode(d);
            l3=l3->next;
            l1=l1->next;
        }

        while(l2){
            int val= l2->val +carry;
            int d=val%10;
            carry=val/10;
            l3->next=new ListNode(d);
            l3=l3->next;
            l2=l2->next;
        }
        if(carry==1){
           l3->next=new ListNode(carry);
        }
        return head->next;
        
        
    }
};
