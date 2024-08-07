class NumArray {
public:
    vector<int> tree;
    int N;
    NumArray(vector<int>& nums) {
        N=nums.size();
        tree.resize(4*N);
        build(1,0,N-1,nums);
    }
    
    void build(int node,int start,int end,vector<int>& nums){
        if(start==end){
            tree[node]=nums[start];
            return;
        }

        int mid=start+(end-start)/2;

        build(2*node,start,mid,nums);
        build(2*node+1,mid+1,end,nums);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
    
    void updateHelper(int node,int start,int end,int index,int val){
          if(start==end){
            tree[node]=val;
            return;
        }

        int mid=start+(end-start)/2;

        if(index<=mid){
            updateHelper(2*node,start,mid,index,val);
        }
        else{
            updateHelper(2*node+1,mid+1,end,index,val);
        }

        tree[node]=tree[2*node]+tree[2*node+1];
    }

    void update(int index, int val) {
        updateHelper(1,0,N-1,index,val);
    }

    int query(int node,int start,int end,int l,int r){
        if(start>r || end<l){
            return 0;
        }
        if(start>=l && end<=r){
            return tree[node];
        }

        int mid=start+(end-start)/2;
        int q1=query(2*node,start,mid,l,r);
        int q2=query(2*node+1,mid+1,end,l,r);

        return q1+q2;
    }

    int sumRange(int left, int right) {
        return query(1,0,N-1,left,right);
    }
};
