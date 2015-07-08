/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *pre, *cur = head;
    while (cur != NULL) {
        pre = cur->prev;
        cur->prev = cur->next;
        cur->next = pre;
        pre = cur;
        cur = cur->prev;
    }
    return pre;
}

