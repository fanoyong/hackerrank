/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head, int data)
{
    Node *cur;
    if(head == NULL) return head;
    cur = head;
    Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = n;
    return head;
}

