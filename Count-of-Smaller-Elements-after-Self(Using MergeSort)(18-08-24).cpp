class Solution {
public:
    void merge(int low,int  mid,int high,vector<pair<int,int>>&numsPair,vector<int> &count){
            vector<pair<int,int>> temp(high-low+1);
            int j=mid+1;
            int i=low;
            int k=0;
            while(i<=mid && j<=high){
                if(numsPair[i].first<=numsPair[j].first){
                    temp[k++]=numsPair[j++];
                }
                else{
                    count[numsPair[i].second]+=high-j+1;
                    temp[k++]=numsPair[i++];
                }
            }
            while(i<=mid){
                temp[k++]=numsPair[i++];
            }
            while(j<=high){
                temp[k++]=numsPair[j++];
            }

            for(int i=low;i<=high;i++){
                numsPair[i]=temp[i-low];
            }
    }

    void mergeSort(int low,int high,vector<pair<int,int>>&numsPair,vector<int> &count){
           if(low>=high){
            return;
           }

           int mid=low+(high-low)/2;
           mergeSort(low,mid,numsPair,count);
           mergeSort(mid+1,high,numsPair,count);
           merge(low,mid,high,numsPair,count);

    }

    vector<int> countSmaller(vector<int>& nums) {
       int n=nums.size();
       vector<pair<int,int>> numsPair;

       for(int i=0;i<n;i++){
        numsPair.push_back({nums[i],i});
       }
       vector<int> count(n,0);
       mergeSort(0,n-1,numsPair,count);

       return count;
    }
};
