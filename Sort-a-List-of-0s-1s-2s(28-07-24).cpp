void sortList(Node *head) 
{ 
    int count[3] = {0, 0, 0}; 
    Node *curr = head; 
 
     while (curr != NULL) 
    { 
        count[curr->data] ++; 
        curr = curr->next; 
    } 
 
    int i = 0; 
    curr = head; 
 
  
    while (curr != NULL) 
    { 
        if (count[i] == 0) 
            i++; 
        else
        { 
            curr->data = i; 
            count[i]--; 
            curr = curr->next; 
        } 
    } 
}
