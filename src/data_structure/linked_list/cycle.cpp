/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
int HasCycle(Node *head) 
{
    Node *elements[100];
    int count = 0;
    int i;
    while (head != NULL) {
        for (i=0; i<count;i++) {
            if (elements[i] == head) {
                return 1;
            }
        }
        elements[count++] = head;
        head = head->next;
    }
    return 0;
}

