Node* helper(int n, int pre[], char preLN[],int &ind){
    if(ind>=n){
        return NULL;
    }
    
    Node* tmp=new Node(pre[ind]);
    
    if(preLN[ind]=='N'){
        ind++;
        tmp->left=helper(n,pre,preLN,ind);
        ind++;
        tmp->right=helper(n,pre,preLN,ind);
    }
    
    return tmp;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int ind=0;
    return helper( n, pre,preLN,ind);
}
