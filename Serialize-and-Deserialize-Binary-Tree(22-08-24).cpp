class Codec {
public:

    
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "null,";
        }
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    TreeNode* helper(queue<string>&q){
       string s=q.front();
       q.pop();
       if(s=="null"){
        return NULL;
       }

       TreeNode* root=new TreeNode(stoi(s));
       root->left=helper(q);
       root->right=helper(q);

       return root;
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                q.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }

        if(s.size()!=0){
            q.push(s);
        }

        return helper(q);
        
    }
};
