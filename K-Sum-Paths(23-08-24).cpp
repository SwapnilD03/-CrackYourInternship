class Solution {
  public:
    void helper(Node *root, int k,int &count,vector<int>paths){
        if(root==NULL){
            return;
        }
        
        paths.push_back(root->data);
        
        helper(root->left,k,count,paths);
        helper(root->right,k,count,paths);
        int sum=0;
        for(int i=paths.size()-1;i>=0;i--){
            sum+=paths[i];
            if(sum==k){
                count++;
            }
        }
        paths.pop_back();
    }
    int sumK(Node *root, int k) {
        vector<int>paths;
        int count=0;
        
        helper(root,k,count,paths);
        return count;
    }
};
