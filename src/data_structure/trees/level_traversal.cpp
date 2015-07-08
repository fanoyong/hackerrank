
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    int head = 0, tail = 0;
    struct node *nodes[10000];
    nodes[tail++] = root;
    while(head != tail) {
        node *n = nodes[head++];
        cout << n->data << " ";
        if (n->left != NULL) {
            nodes[tail++] = n->left;
        }
        if (n->right != NULL) {
            nodes[tail++] = n->right;
        }
    }
}

