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

bool search(Node* r, int x) {
    if (r == NULL)
        return false;

    if (r->data == x)
        return true;

    if (x < r->data)
        return search(r->left, x);

    return search(r->right, x);
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

    cout << "Minimum = " << minimum(root);

    cout << "\nEnter new value to insert: ";
    cin >> x;
    root = insert(root, x);

    cout << "Enter value to search: ";
    cin >> x;

    cout << (search(root, x) ? "Found" : "Not Found");
    return 0;
}

 