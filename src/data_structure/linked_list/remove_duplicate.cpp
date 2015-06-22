/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL) return head;

    Node *pre, *cur, *temp;
    pre = head;
    cur = head->next;
    while (cur != NULL)
    {
        if (pre->data == cur->data)
        {
            temp = cur->next;
            pre->next = cur->next;
            free(cur);
            cur = temp;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}

