/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
int HasCycle(Node head) {
    if (head == null || head.next == null) {
        return 0;
    }
    HashSet<Node> set = new HashSet<Node>();
    while (head != null) {
        if (!set.contains(head)) {
            set.add(head);
        } else {
            return 1;
        }
        head = head.next;
    }
    return 0;
}

