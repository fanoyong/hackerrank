
/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/
int height(node * root)
{
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    if (root->left == NULL) {
        return height(root->right) + 1;
    }
    if (root->right == NULL) {
        return height(root->left) + 1;
    }
    
    return max(height(root->left), height(root->right)) + 1;
}

int max(int a, int b) {
    return a>b? a:b;
}
  

