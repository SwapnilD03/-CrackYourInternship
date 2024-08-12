

class twoStacks {
  int *arr;
  int top1,top2;
  int size;
  public:
    twoStacks(int N=100) {
        arr=new int[N];
        size=N;
        top1=-1;
        top2=N;
    }

    
    void push1(int x) {
        if(top1+1!=top2){
            top1++;
            arr[top1]=x;
        }
        else{
            return;
        }
    }

    void push2(int x) {
        if(top2-1!=top1){
            top2--;
            arr[top2]=x;
        }
        else{
            return;
        }
    }

   
    int pop1() {
        if(top1==-1){
            return -1;
        }
        
        int val=arr[top1];
        top1--;
        return val;
    }

    
    int pop2() {
        if(top2==size){
            return -1;
        }
        
        int val=arr[top2];
        top2++;
        return val;
    }
};
