#include<iostream>

using namespace std;
 
 pair<int,int> ceilFloor(int arr[],int n,int x){
     int low=0,high=n-1;
     int c=-1,f=-1;
     while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]>=x){
            c=arr[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     low=0;high=n-1;
     while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]<=x){
            f=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
     }

     pair<int,int> ans=make_pair(c,f);

     return ans;

 }

 int main(){

    int arr[10];

    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<10;i++){
       cout<<"Enter an element : ";
       cin>>arr[i];
    }
      
    for(int i=0;i<10;i++){
        for(int j=0;j<10-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(auto i:arr){
        cout<<i<<" ";
    }
   
    int x;
    cout<<"Enter the value : ";

    cin>>x;  

    pair<int,int> p=ceilFloor(arr,n,x);
    
    cout<<"Ceil : "<<p.first<<" and Floor : "<<p.second<<endl;
    

    return 0;
 }
