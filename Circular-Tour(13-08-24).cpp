class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
       int deficient=0;
       int balance=0;
       int start=0;
       
       for(int i=0;i<n;i++){
           balance+=p[i].petrol-p[i].distance;
           if(balance<0){
               deficient+=balance;
               balance=0;
               start=i+1;
           }
       }
       
       if(deficient+balance>=0){
           return start;
       }
       else{
           return -1;
       }
       
    }
};
