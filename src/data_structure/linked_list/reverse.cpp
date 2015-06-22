/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    Node *p, *q, *r;
    if (head == NULL || head->next == NULL)
    {
        return head;
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

    return p;
}

