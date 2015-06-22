/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int x)
{
    Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    if(head == NULL)
    {
        n->next = NULL;
        return n;
    }
    n->next = head;
    return n;
}

