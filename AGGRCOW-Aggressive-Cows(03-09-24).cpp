#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>> n >>c;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        sort(a.begin(),a.end());
        int l=0,h=a[n-1],mid,gap=0;
        while(l<=h){
            mid=l+(h-l)/2;
            int cnt=1,left=0;
            for(int i=1;i<n && cnt<c;i++){
                if(a[i]-a[left]>=mid){
                    left=i;cnt++;
                }
            }

            if(cnt>=c){
               gap=mid;
               l=mid+1;
            }
            else{
                h=mid-1;
            }
        }

        cout<<gap<<endl;
    }
}
