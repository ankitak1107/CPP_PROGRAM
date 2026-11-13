#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* r, int x) {
    if (r == NULL)
        return new Node{x, NULL, NULL};

    if (x < r->data)
        r->left = insert(r->left, x);
    else
        r->right = insert(r->right, x);

    return r;
}

int height(Node* r) {
    if (r == NULL)
        return 0;

    int a = height(r->left);
    int b = height(r->right);
    return 1 + (a > b ? a : b);
}

int minimum(Node* r) {
    while (r->left != NULL)
        r = r->left;
    return r->data;
}

int main() {
    Node* root = NULL;
    int n, x;

    cout << "Enter number of nodes (1-100): ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid number of nodes";
        return 0;
    }

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Height (nodes in longest path) = " << height(root);
    cout << "\nMinimum = " << minimum(root);

    cout << "\nEnter new value: ";
    cin >> x;
    root = insert(root, x);

    cout << "New value inserted.";
    return 0;
}

 