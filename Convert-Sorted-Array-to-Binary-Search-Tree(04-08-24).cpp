class Solution {
public:
    TreeNode* Helper(vector<int>& nums,int left,int right){
        if(left>right){
            return NULL;
        }

        int mid=left+(right-left)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=Helper(nums,left,mid-1);
        root->right=Helper(nums,mid+1,right);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Helper(nums,0,nums.size()-1);

    }
};
