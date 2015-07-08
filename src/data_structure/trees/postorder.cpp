/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/


void Postorder(node *root) {
    if (root->left != NULL) {
        Postorder(root->left);
    }
    if (root->right != NULL) {
        Postorder(root->right);
    }
    cout << root->data << " ";    
}

