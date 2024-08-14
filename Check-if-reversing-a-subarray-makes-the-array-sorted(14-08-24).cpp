#include <iostream>
#include<algorithm>
using namespace std;

bool check(int arr[],int n){
    int x=-1,y=-1;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            if(x!=-1){
                x=i;
            }
            y=i+1;
        }
    }

    if(x!=-1){
        reverse(arr+x,arr+y+1);

        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                return false;
            }
        }

    }
    return true;
}


int main(){
    int arr[] = { 1, 2, 5, 4, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    check(arr, n) ? (cout << "Yes" << endl) : (cout << "No" << endl); 
    return 0;
}
