class BSTIterator {
public:
    vector<TreeNode*>nodes;
    int ind=0;
    void getInorder(TreeNode* root){
        if(root==NULL){
            return;
        }

        getInorder(root->left);
        nodes.push_back(root);
        getInorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        getInorder(root);
    }
    
    int next() {
        int val=nodes[ind]->val;
        ind++;
        return val;
    }
    
    bool hasNext() {
        if(ind<nodes.size()){
            return true;
        }
        else{
            return false;
        }
    }
};
