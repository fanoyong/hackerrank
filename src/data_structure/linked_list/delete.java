/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
    // This is a "method-only" submission. 
    // You only need to complete this method. 

Node Delete(Node head, int position) {
    if (head == null) {
        return null;
    }
    if (position == 0) {
        Node n = head.next;
        head = null;
        return n;
    }
    Node cur = head, prev = head;
    int i = 0;
    while (cur != null && i++ < position) {
        prev = cur;
        cur = cur.next;
    }
    prev.next = cur.next;
    cur = null;
    return head;
}


