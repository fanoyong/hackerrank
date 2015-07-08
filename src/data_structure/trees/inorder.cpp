/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Inorder(node *root) {
    if (root->left != NULL) {
        Inorder(root->left);
    }
    cout << root->data << " ";   
    if (root->right != NULL) {
        Inorder(root->right);
    }
}

