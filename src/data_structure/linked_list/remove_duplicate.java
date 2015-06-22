Node RemoveDuplicates(Node head) {
    if (head == null || head.next == null) {
        return head;
    }
    Node pre, cur, temp;
    pre = head;
    cur = head.next;
    while (cur != null) {
        if (pre.data == cur.data) {
            temp = cur.next;
            pre.next = temp;
            cur = temp;
        } else {
            pre = cur;
            cur = cur.next;
        }
    }
    return head;
}

