class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr=head;

        unordered_map<ListNode*,bool> visited;

        while(curr!=NULL){
            if(visited[curr]==true){
                return true;
            }
            visited[curr]=true;
            curr=curr->next;
        }
        return false;
    }
};
