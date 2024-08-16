class Solution{
    public:
    vector<int> solve(Node* root){
        if(root==NULL){
            return {0,1,INT_MAX,INT_MIN};
        }
        
        if(root->left==NULL && root->right==NULL){
            return {1,1,root->data,root->data};
        }
        
        vector<int> left=solve(root->left);
        vector<int> right=solve(root->right);
        
        int leftSize=left[0],isBSTLeft=left[1],miniLeft=left[2],maxiLeft=left[3];
        
        int rightSize=right[0],isBSTRight=right[1],miniRight=right[2],maxiRight=right[3];
        
        if((isBSTLeft==1 && isBSTRight==1) &&(root->data>maxiLeft && root->data<miniRight)){
            return {1+leftSize+rightSize,1,min(root->data,miniLeft),max(root->data,maxiRight)};
            
        } 
        
        else{
            return {max(leftSize,rightSize),0,0,0};
        }
        
        
    }
    int largestBst(Node *root)
    {
    	return solve(root)[0];
    }
};
