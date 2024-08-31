class Solution {
public:
    
    int mergeSort(vector<long>&sum,int l,int h,int lower,int upper){
        int count=0;

        if(h-l<=1){
            if(h-l==1){
                return (lower<=sum[l] && sum[l]<=upper);
            }
            else{
                return 0;
            }
        }

        int mid=l+(h-l)/2;
        int leftSum=mergeSort(sum,l,mid,lower,upper);
        int rightSum=mergeSort(sum,mid,h,lower,upper);

        int i=l,j=mid;
        int n=0,m=0;

        vector<long> vec(h-l,0);
        int k=0;

        while(i<mid){
            while(mid+n<h && sum[mid+n]<sum[i]+lower){
                n++;
            }
            while(mid+m < h && sum[mid+m]<=sum[i]+upper){
                m++;
            }
            while(j<h && sum[j]<sum[i]){
                vec[k++]=sum[j++];
            }
            vec[k++]=sum[i++];
            count+=m-n;
        }
        while(j<h){
            vec[k++]=sum[j++];
        }

        for(int i=0;i<vec.size();i++){
            sum[l+i]=vec[i];
        }
        return leftSum+rightSum+count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long> sum(n,0);
        sum[0]=nums[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+nums[i];
        }
        return mergeSort(sum,0,n,lower,upper);
    }
};
