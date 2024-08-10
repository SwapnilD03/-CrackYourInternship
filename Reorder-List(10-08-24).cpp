class Solution {
public:
    void reorderList(ListNode* head) {
        int n=0;
        ListNode *curr=head;
        while(curr!=NULL){
            curr=curr->next;
            n++;
        }
        vector<ListNode*> list(n);
        curr=head;
        for(int i=0;i<n;i++){
            list[i]=curr;
            curr=curr->next;
        }

       int low=0,high=n-1;
       vector<ListNode*> v;
       while(low<high){
         v.push_back(list[low]);
         v.push_back(list[high]);
         low++;high--;
       }
       v.push_back(list[low]);

       head->next=NULL;
       curr=head;

       for(int i=1;i<n;i++){
        ListNode* node=new ListNode(v[i]->val);
        curr->next=node;
        curr=curr->next;
       }
    }
};
