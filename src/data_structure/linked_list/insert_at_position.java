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

Node InsertNth(Node head, int data, int position) {
    Node n = new Node();
    n.data = data;
    if (head == null) {
        n.next = null;
        return n;
    }
    if (position == 0) {
        n.next = head;
        return n;
    }
    Node prev = head;
    Node cur = head;
    int i = 1;
    do {
        prev = cur;
        cur = cur.next;
    } while(cur != null && i++ < position);
    prev.next = n;
    n.next = cur;
    return head;
}

