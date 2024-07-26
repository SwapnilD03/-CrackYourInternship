class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* dummyHead=new ListNode(0);
        if(list1->val<list2->val){
        ListNode* node=new ListNode(list1->val);
        list1=list1->next;
        dummyHead->next=node;
        }
        else{
            ListNode* node=new ListNode(list2->val);
            list2=list2->next;
            dummyHead->next=node;
        }

        ListNode* curr=dummyHead->next;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
           ListNode* node=new ListNode(list1->val);
           curr->next=node;
           list1=list1->next;
        }
        else{
            ListNode* node=new ListNode(list2->val);
            curr->next=node;
            list2=list2->next;
        }
        curr=curr->next;
        }

        while(list1!=NULL){
            ListNode* node=new ListNode(list1->val);
            curr->next=node;
            list1=list1->next;
            curr=curr->next;
        }

        while(list2!=NULL){
            ListNode* node=new ListNode(list2->val);
            curr->next=node;
            list2=list2->next;
            curr=curr->next;
        }

        return dummyHead->next;

    }
};
