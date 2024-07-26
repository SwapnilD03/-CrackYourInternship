class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> n;
        ListNode* curr=head;
        while(curr!=NULL){
            n.push_back(curr->val);
            curr=curr->next;
        }

        int left=0,right=n.size()-1;
        while(left<right){
            if(n[left]!=n[right]){
                return false;
            }
            left++;right--;
        }

        return true;
    }
};
