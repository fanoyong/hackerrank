/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL) {
        cout << head->data << endl;
        return;
    }
    Node *p, *q, *r;
    p = head;
    q = head->next;
    p->next = NULL;

    do
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    } while (r != NULL);

    // at this moment, p is header.
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

