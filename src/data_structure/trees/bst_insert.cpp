/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value)
{
    node * n = (struct node *) malloc (sizeof(struct node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    if (root == NULL)
    {
        return n;
    }
    if (root->data > value) {
        if (root->left == NULL)
        {
            root->left = n;
            return NULL;
        } 
        else 
        {
            insert(root->left, value);
        }
    } else {
        if (root->right == NULL)
        {
            root->right = n;
            return NULL;
        } 
        else 
        {
            insert(root->right, value);
        }
    }


   return root;
}

