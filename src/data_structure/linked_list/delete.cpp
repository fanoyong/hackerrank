/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    if (head == NULL) return NULL;
    if (position == 0)
    {
        Node *c = head->next;
        free(head);
        return c;
    }
    Node *pre = head, *cur = head;
    int i = 0;
    while (cur != NULL && i++ < position)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    free(cur);
    return head;
}

