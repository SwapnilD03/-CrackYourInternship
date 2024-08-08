class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        unordered_map<int,int> mp;
        ListNode* curr=head;
        while(curr!=NULL){
            if(mp.find(curr->val)!=mp.end()){
                mp[curr->val]++;
            }
            else{
                mp[curr->val]=1;
            }
            curr=curr->next;
        }

        curr=head;
        while(curr!=NULL && mp[curr->val]>1){
            curr=curr->next;
        }
        if(curr==NULL){
            return NULL;
        }
        head=curr;
        
        if(curr->next==NULL){
            return head;
        }
        ListNode* nextNode=curr->next;
        while(nextNode!=NULL){
           if(mp[nextNode->val]==1){
            curr->next=nextNode;
            curr=nextNode;
           }
           nextNode=nextNode->next;
        }
        curr->next=nextNode;
        return head;
    }
};
