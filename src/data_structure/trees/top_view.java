
void Left(Node root)
{
    if (root.left != null) {
        Left(root.left);
    }
    System.out.print(root.data + " ");
}

void Right(Node root)
{
    System.out.print(root.data + " ");
    if (root.right != null) {
        Right(root.right);
    }
}

void top_view(Node root)
{
    if (root.left != null) {
        Left(root.left);
    }
    System.out.print(root.data + " ");
    if (root.right != null) {
        Right(root.right);
    }
}


