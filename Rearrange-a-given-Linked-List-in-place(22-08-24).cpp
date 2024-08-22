class Solution {
  public:
    void reorderList(Node* head) {
       int n=0;
       Node* curr=head;
       while(curr!=NULL){
           n++;
           curr=curr->next;
       }
       
       vector<Node*> nodes(n);
       curr=head;
       int i=0;
       while(curr!=NULL){
           nodes[i]=curr;
           i++;
           curr=curr->next;
       }
       vector<Node*> v;
       int l=0,h=n-1;
       while(l<h){
           v.push_back(nodes[l]);
           v.push_back(nodes[h]);
           l++;h--;
       }
       
       v.push_back(nodes[l]);
       
       head->next=NULL;
       curr=head;
       for(int i=1;i<n;i++){
           Node* temp=new Node(v[i]->data);
           curr->next=temp;
           curr=curr->next;
       }
       
    }
};
