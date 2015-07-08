
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    int count = 0;
    struct node *nodes[10000];
    nodes[count++] = root;
    while(count > 0) {
        node *n = nodes[--count];
        cout << n->data << " ";
        if (n->left != NULL) {
            nodes[count++] = n->left;
        }
        if (n->right != NULL) {
            nodes[count++] = n->right;
        }
    }
}

