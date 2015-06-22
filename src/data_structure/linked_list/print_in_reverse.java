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

void ReversePrint(Node head) {
    if (head == null) {
        return;
    }
    if (head.next == null) {
        System.out.println(head.data);
        return;
    }
    Stack<Node> queue = new Stack<Node>();
    while (head != null) {
        queue.push(head);
        head = head.next;
    }
    while (!queue.isEmpty()) {
        System.out.println(queue.pop().data);
    }
}

