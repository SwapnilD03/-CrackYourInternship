class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0;
        ListNode* currA=headA;
        while(currA!=NULL){
            l1++;
            currA=currA->next;
        }
        int l2=0;
        ListNode* currB=headB;
        while(currB!=NULL){
            l2++;
            currB=currB->next;
        }
        currA=headA;
        currB=headB;
        if(l1>l2){
            int diff=l1-l2;
            int i=0;
            while(i<diff){
                currA=currA->next;i++;
            }
        }
        else if(l2>l1){
            int diff=l2-l1;
            int i=0;
            while(i<diff){
                currB=currB->next;i++;
            }
        }

        while(currA!=NULL && currB!=NULL){
            if(currA==currB){
                return currA;
            }
            currA=currA->next;
            currB=currB->next;
        }

        return NULL;

    }
};
