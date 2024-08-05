 class compare{
    public :
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;
        if(lists.size()==0){
            return NULL;
        }
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
            minHeap.push(lists[i]);
            }
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(minHeap.size()>0){
            ListNode* temp=minHeap.top();
            minHeap.pop();
            if(temp->next!=NULL){
                    minHeap.push(temp->next); 
            }

            if(head==NULL){
                head=temp;
                tail=temp;
            }
            else{
                 tail->next=temp;
                 tail=temp;
            }
        }
        return head;

    }
};
