class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){

                Node* frontNode=q.front();
                q.pop();
                
                if(frontNode->left!=NULL){
                    q.push(frontNode->left);
                }

                if(frontNode->right!=NULL)
                {
                    q.push(frontNode->right);
                }

                Node* temp=q.front();
                frontNode->next=temp;

                if(i==size-1){
                    frontNode->next=NULL;
                }
            }
        }
        return root;
    }
};
