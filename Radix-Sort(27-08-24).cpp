int getMax(int arr[],int  n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    
    return maxi;
}

void countSort(int arr[],int n ,int pos,int k){
    int b[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        ++count[(arr[i]/pos)%10];
    }
    for(int i=1;i<k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=b[i];
    }
    
}
void radixSort(int arr[], int n) 
{ 
   int max=getMax(arr,n);
   for(int pos=1;max/pos>0;pos*=10){
       countSort(arr,n,pos,10);
   }
} 
