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
Node Reverse(Node head) {
    Node p, q, r;
    if (head == null || head.next == null) {
        return head;
    }
    p = head;
    q = head.next;
    p.next = null;
    do {
        r = q.next;
        q.next = p;
        p = q;
        q = r;
    } while (r != null);
    return p;
}

