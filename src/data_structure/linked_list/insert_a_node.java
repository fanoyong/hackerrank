/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
Node Insert(Node head,int x) {
    if(head == null) {
        return null;
    }
    Node pre, cur, newNode;
    newNode = new Node();
    newNode.data = x;
    cur = head;
    while(cur.next != null) {
        cur = cur.next;
    }
    cur.next = newNode;
    return head;
}

