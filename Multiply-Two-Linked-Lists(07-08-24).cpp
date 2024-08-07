class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long mod=1000000007;
        long long num1=0,num2=0;
        while(first!=NULL){
            num1=(num1*10 + first->data)%mod;
            first=first->next;
        }
        while(second!=NULL){
            num2=(num2*10 + second->data)%mod;
            second=second->next;
        }
        
        long long ans=(num1*num2)%mod;
        return ans;
    }
};
