/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
int contains(node * root, int v) {
    if (root == NULL) {
        return 0;
    }
    return (root->data == v) || contains(root->left, v) || contains(root->right, v);
}

node * lca(node * root, int v1, int v2)
{
    if (root == NULL) {
        return NULL;
    }
    if (contains(root->left, v1) && contains(root->left, v2)) {
        return lca(root->left, v1, v2);
    }
    if (contains(root->right, v1) && contains(root->right, v2)) {
        return lca(root->right, v1, v2);
    }
    return root;
}


