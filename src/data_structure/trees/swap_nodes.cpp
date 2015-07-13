#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node_t {
    int index;
    int level;
    struct node_t *left;
    struct node_t *right;
}node;

int N;
int H;
int T;
node *root;

void print_in_order(node *cur) {
    if (cur == NULL) {
        return;
    }
    if (cur->left != NULL) {
        print_in_order(cur->left);
    }
    cout << cur->index << " ";
    if (cur->right != NULL) {
        print_in_order(cur->right);
    }
}

node * get_node(node * cur, int index) {
    if (cur == NULL) {
        return 0;
    }
    if (cur->index == index) {
        return cur;
    }
    node * n = get_node(cur->left, index);
    if (!n) {
        n = get_node(cur->right, index);
    }
    return n;
}

int get_height(node *cur) {
    if (cur == NULL) {
      return -1;
   }
   int left = get_height(cur->left);
   int right = get_height(cur->right); 
   return 1 + std::max(left, right);
}

void swap(node * cur, int i) {
    if (cur == NULL || cur->level > i) {
        return;
    }
    if (cur->level == i) {
        // cout << "swap " << cur->index << " with height " << i << endl;
        node *t = cur->left;
        cur->left = cur->right;
        cur->right = t;
    }
    if (cur->left != NULL) {
        swap(cur->left, i);
    }
    if (cur->right != NULL) {
        swap(cur->right, i);
    }
}

int main() {
    int a,b;
    int i;
    cin >> N;
    root = (struct node_t *)malloc(sizeof(struct node_t));
    root->index = 1;
    root->level = 1;
    root->left = NULL;
    root->right = NULL;
    for (i=1; i<=N; i++) {
        cin >> a >> b;
        // cout << "a/b " << a << b << endl;
        node *n = get_node(root,i);
        if (!n) {
            n = (struct node_t *)malloc(sizeof(struct node_t));
            n->index = i;
            // cout << "Node index: " << n->index << endl;
        }
        if (a == -1) {
            n->left = NULL;
        } else {
            node *n_left = (struct node_t *)malloc(sizeof(struct node_t));
            n_left->index = a;
            n_left->level = n->level + 1;
            n_left->left = NULL;
            n_left->right = NULL;
            n->left  = n_left;
            // cout << "Node Left index: " << n_left->index << endl;
        }
        if (b == -1) {
            n->right = NULL;
        } else {
            node *n_right = (struct node_t *)malloc(sizeof(struct node_t));
            n_right->index = b;
            n_right->level = n->level + 1;
            n_right->left = NULL;
            n_right->right = NULL;
            n->right  = n_right;
            // cout << "Node Right index: " << n_right->index << endl;
        }
    }
    cin >> T;
    H = get_height(root);
    // cout << "height: " << H << endl;
    while (T--) {
        cin >> a;
        for (i=a; i<=H; i+=a) {
            // cout << i << endl;
            swap(root, i);
        }
        print_in_order(root);
        cout << endl;
    }
    return 0;
}
