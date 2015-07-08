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

Node Reverse(Node head) {
    if (head == null || head.next == null) {
        return head;
    }
    Node pre=head, cur = head;
    while (cur != null) {
        pre = cur.prev;
        cur.prev = cur.next;
        cur.next = pre;
        pre = cur;
        cur = cur.prev;
    }
    return pre;
}
