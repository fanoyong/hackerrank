/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    node *cur = root;
    int len = s.length();
    int i = 0;
    for(i=0; i<=len; i++)
    {
        if (cur->data != '\0') {
            cout << cur->data;
            cur = root;
            i--;
        } else {
            if(s[i] == '0') {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        } 
    }
}

