/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    Node *p, *q, *r;
    if (head == NULL)
    {
        return 0;
    }
    if (head->next == NULL)
    {
        return head->data;
    }
    p = head;
    q = head->next;
    p->next = NULL;
    do
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    } while(r != NULL);

    Node *reverse_head = p;
    int i = 0;
    while (reverse_head != NULL && i++ < positionFromTail)
    {
        reverse_head = reverse_head->next;
    }
    return reverse_head->data;
}
