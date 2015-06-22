/*
  Insert Node at a given position in a linked list 
  The linked list will not be empty and position will always be valid
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int x, int position)
{
    int i;
    Node *prev, *cur;
    Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    if (position == 0)
    {
        n->next = head;
        return n;
    }
    if (head == NULL)
    {
        n->next = NULL;
        return n;
    }
    cur = head;
    i=1;
    do
    {
        prev = cur;
        cur = cur->next;
    } while(cur != NULL && i++ < position);
    prev->next = n;
    n->next = cur;
    return head;
}

