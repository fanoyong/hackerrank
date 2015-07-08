/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    Node *target = headA, *source = headB;
    while (target != NULL) {
        while (source != NULL) {
            if (target->next == source->next && target->data == source->data) {
                return target->data;
            }
            source = source->next;
        }
        target = target->next;
        source = headB;
    }
    return 0;
}

