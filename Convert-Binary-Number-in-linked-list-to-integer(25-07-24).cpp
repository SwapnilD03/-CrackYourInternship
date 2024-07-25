class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode* curr=head;
        while(curr!=NULL){
            n++;
            curr=curr->next;
        }
        int ans=0;
        curr=head;
        while(curr!=NULL){
            ans+=pow(2,n-1)*curr->val;
            n--;
            curr=curr->next;
        }
        return ans;
    }
};
