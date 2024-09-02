#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        m--;n--;

        vector<int> x(m);
        vector<int> y(n);

        for(int i=0;i<m;i++) cin>>x[i];
        for(int i=0;i<n;i++) cin>>y[i];

        sort(x.rbegin(),x.rend());
        sort(y.rbegin(),y.rend());

        int ans=0;
        int i=0,j=0;

        int hc=1,vc=1;

        while(i<m && j<n){
            if(x[i]>y[j]){
                ans+=x[i++]*vc;
                hc++;
            }
            else{
                ans+=y[j++]*hc;
                vc++;
            }
        }

        while(i<m){
             ans+=x[i++]*vc;
                hc++;
        }

        while(j<n){
             ans+=y[j++]*hc;
                vc++;
        }

        cout<<ans<<endl;
    }
    return 0;
}
