 /* Node is defined as :
 class Node 
    int data;
    Node left;
    Node right;
    
    */

static Node Insert(Node root,int value) {
    if (root == null) {
        Node n = new Node();
        n.data = value;
        n.left = null;
        n.right = null;
        return n;
    }
    if (root.data > value) {
        if (root.left == null) {
            Node n = new Node();
            n.data = value;
            n.left = null;
            n.right = null;
            root.left = n;
        } else {
            Insert(root.left, value);
        }
    } else {
        if (root.right == null) {
            Node n = new Node();
            n.data = value;
            n.left = null;
            n.right = null;
            root.right = n;
        } else {
            Insert(root.right, value);
        }
    }
    return root;
}
