class Solution 
{
    public:
    
	int minSwaps(vector<int>&nums)
	{
	    int N=nums.size();
	    vector<pair<int,int>> vec(N);
	    
	    for(int i=0;i<N;i++){
	        vec[i]={nums[i],i};
	    }
	    
	    sort(vec.begin(),vec.end());
	    
	    int count=0;
	    
	    for(int i=0;i<N;i++){
	        if(vec[i].second!=i){
	            count++;
	            swap(vec[i],vec[vec[i].second]);
	            --i;
	        }
	    }
	    
	    return count;
	}
};
