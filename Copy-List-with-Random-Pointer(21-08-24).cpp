class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> oldToCopy;
        oldToCopy[NULL]=NULL;

        Node* curr=head;

        while(curr!=NULL){
            Node* copy=new Node(curr->val);
            oldToCopy[curr]=copy;
            curr=curr->next;
        }

        curr=head;
        while(curr!=NULL){
            Node* copy=oldToCopy[curr];
            copy->next=oldToCopy[curr->next];
            copy->random=oldToCopy[curr->random];
            curr=curr->next;
        }

        return oldToCopy[head];
    }
};
