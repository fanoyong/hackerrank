   /*
    
    class Node 
       int data;
       Node left;
       Node right;
   */
int height(Node root) {
if (root.left == null && root.right == null) {
        return 1;
    }
    if (root.left == null) {
        return height(root.right) + 1;
    }
    if (root.right == null) {
        return height(root.left) + 1;
    }
    
    return max(height(root.left), height(root.right)) + 1;
}

int max(int a, int b) {
    return a>b? a:b;
}
