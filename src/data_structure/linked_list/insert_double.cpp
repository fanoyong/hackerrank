/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev
   }
*/

Node* SortedInsert(Node *head, int data)
{
    Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    if (head == NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
        return new_node;
    } else if (data < head->data) {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        return new_node;
    } else if (head->next == NULL) {
        head->next = new_node;
        new_node->next = NULL;
        new_node->prev = head;
        return head;
    }
    Node *pre = head, *cur = head->next;
    while (cur != NULL) {
        if (cur->data > data) {
            pre->next = new_node;
            cur->prev = new_node;
            new_node->next = cur;
            new_node->prev = pre;
            return head;
        }
        pre = cur;
        cur = cur->next;
    }
    pre->next = new_node;
    new_node->next = NULL;
    new_node->prev = pre;
    return head;
}

