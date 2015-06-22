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

Node Insert(Node head,int x) {
    Node n = new Node();
    n.data = x;
    if (head == null) {
        n.next = null;
        return n;
    }
    n.next = head;
    return n;
}

