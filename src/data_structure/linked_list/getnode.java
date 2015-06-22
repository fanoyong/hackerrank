/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
    
int GetNode(Node head,int n) {

    if (head == null) {
        return 0;
    }
    if (head.next == null) {
        return head.data;
    }
    Stack<Node> stack = new Stack<Node>();
    while (head != null) {
        stack.push(head);
        head = head.next;
    }
    
    for (int i = 0; i<n; i++) {
        stack.pop();
    }
    return stack.pop().data;
}

