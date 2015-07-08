/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
     Node prev;
  }
*/

Node SortedInsert(Node head, int data) {
    Node node = new Node();
    node.data = data;

    if (head == null) {
        node.next = null;
        node.prev = null;
        return node;
    } else if (head.data > data) {
        node.next = head;
        node.prev = null;
        head.prev = node;
        return node;
    } else if (head.next == null) {
        head.next = node;
        node.prev = head;
        node.next = null;
        return head;
    }
    Node pre = head;
    Node cur = head.next;    
    while (cur != null && cur.data < data) {
        pre = cur;
        cur = cur.next;
    }
    pre.next = node;
    node.prev = pre;
    node.next = cur;
    if (cur != null) {
        cur.prev = node;
    }
    return head;
}

