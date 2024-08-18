class Solution{
    public:
    Node* lca(Node* root,int a,int b){
        if(root==NULL){
            return NULL;
        }
        
        if(root->data==a || root->data==b) return root;
        
        Node* left=lca(root->left,a,b);
        Node* right=lca(root->right,a,b);
        
        if(left!=NULL && right!=NULL) return root;
        
        return(left!=NULL) ? left:right;
    }
    
    int Dist(Node* root,int a,int dist){
        if(root==NULL){
            return -1;
        }
        
        if(root->data ==a) return dist;
        
        int left=Dist(root->left,a,dist+1);
        if(left!=-1)  return left;
        return Dist(root->right,a,dist+1);
    }
    int findDist(Node* root, int a, int b) {
       Node* lcaNode=lca(root,a,b);
       
       int d1=Dist(lcaNode,a,0);
       int d2=Dist(lcaNode,b,0);
       
       return d1+d2;
    }
};
