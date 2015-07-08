/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
int FindMergeNode(Node headA, Node headB) {
    Node cur = headA;
    HashSet<Node> set = new HashSet<Node>();
    while (cur != null) {
        set.add(cur);
        cur = cur.next;
    }
    cur = headB;
    while (cur != null) {
        if (set.contains(cur)) {
            return cur.data;
        }
        cur = cur.next;
    }
    return 0;
}

