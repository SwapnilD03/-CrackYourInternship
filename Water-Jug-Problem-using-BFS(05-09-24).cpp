class Solution{
	public:
	int gcd(int a,int b){
	    if(b==0) return a;
	    
	    return gcd(b,a%b);
	}
	int bfs(int a,int b,int d){
	    int from=a;
	    int to=0;
	    int cnt=1;
	    
	    while(from!=d && to!=d){
	        int tmp=min(from,b-to);
	        to+=tmp;
	        from-=tmp;
	        cnt++;
	        
	        if(from==d || to==d){
	            break;
	        }
	        
	        if(from==0){
	            from=a;
	            cnt++;
	        }
	        
	        if(to==b){
	            to=0;
	            cnt++;
	        }
	    }
	    
	    return cnt;
	    
	   
	}
	int minSteps(int m, int n, int d)
	{
	    if(m>n) swap(m,n);
	    
	    if(d>n) return -1;
	    
	    if((d%gcd(n,m))!=0) return -1;
	    
	    return min(bfs(n,m,d),bfs(m,n,d));
	}
};
