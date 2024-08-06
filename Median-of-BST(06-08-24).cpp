void getInorder(struct Node*  root,vector<int>&inorder){
    if(root==NULL){
        return;
    }
    
    getInorder(root->left,inorder);
    inorder.push_back(root->data);
    getInorder(root->right,inorder);
}
float findMedian(struct Node *root)
{
    vector<int> inorder;
    getInorder(root,inorder);
    
    int n=inorder.size();
    
    if(n%2!=0){
        return inorder[n/2];
    }
    
    else{
        return (inorder[n/2]+inorder[n/2 -1])/2.0;
    }
}
