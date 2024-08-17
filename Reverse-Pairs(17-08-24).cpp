class Solution {
    private:
    void merge(vector<int>& nums,int low,int mid,int high,int &count){
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2*(long long)nums[j]){
                j++;
            }
            count+=j-(mid+1);
        }

        int i=low;j=mid+1;
        vector<int> temp(high-low+1,0);
        int k=0;
        while(i<=mid && j<=high){
            if(nums[i]>nums[j]){
                temp[k++]=nums[j++];
            }
                else{
                    temp[k++]=nums[i++];
                }
            }
        

        while(i<=mid){
            temp[k++]=nums[i++];
        }

        while(j<=high){
            temp[k++]=nums[j++];
        }
        k=0;
        for(int i=low;i<=high;i++){
            nums[i]=temp[k++];
        }
    }

    
    void mergeSort(vector<int>& nums,int low,int high,int&count){
        if(low>=high){
            return ;
        }

        int mid=low+(high-low)/2;

        mergeSort(nums,low,mid,count);
        mergeSort(nums,mid+1,high,count);
        merge(nums,low,mid,high,count);
        
    }
    public:
    int reversePairs(vector<int>& nums) {
        int count=0;
        mergeSort(nums,0,nums.size()-1,count);
        return count;
    }
};
