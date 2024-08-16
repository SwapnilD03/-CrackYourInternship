class Solution{
public:
Node* segregateEvenOdd(Node* head)
{
    
    Node* evenStart = NULL;
    
    Node* evenEnd = NULL;
    
    
    Node* oddStart = NULL;
    Node* oddEnd = NULL;
   
    Node* currNode = head;

    while (currNode != NULL) {
         int val=currNode->data;

         if(val%2==0){
            if(evenStart==NULL){
                evenStart=currNode;
                evenEnd=evenStart;
            }
            else{
                evenEnd->next=currNode;
                evenEnd=currNode;
            }
         }

         else{
             if(oddStart==NULL){
                oddStart=currNode;
                oddEnd=evenStart;
            }
            else{
                oddEnd->next=currNode;
                oddEnd=currNode;
            }
         }

         currNode=currNode->next;
        }

        
    if (oddStart == NULL || evenStart == NULL)
        return;

    
    evenEnd->next = oddStart;
    oddEnd->next = NULL;


   return evenStart;
 }
};
