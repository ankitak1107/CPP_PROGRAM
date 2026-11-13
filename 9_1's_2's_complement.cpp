#include <iostream>
#include <string>
using namespace std;

struct Node {
    int bit;
    Node *prev, *next;
};

int main() {
    string s;
    Node *head = NULL, *tail = NULL;

    cout << "Enter binary number: ";
    cin >> s;

    if (s.empty()) {
        cout << "Invalid binary number";
        return 0;
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0' && s[i] != '1') {
            cout << "Invalid binary number";
            return 0;
        }

        Node* t = new Node{s[i] - '0', tail, NULL};
        if (head == NULL)
            head = t;
        else
            tail->next = t;
        tail = t;
    }

    cout << "1's complement: ";
    for (Node* t = head; t != NULL; t = t->next)
        cout << 1 - t->bit;

    // Change the stored bits to their 1's complement.
    for (Node* t = head; t != NULL; t = t->next)
        t->bit = 1 - t->bit;

    // Add 1 from the right side to get 2's complement.
    Node* t = tail;
    int carry = 1;

    while (t != NULL && carry) {
        int sum = t->bit + carry;
        t->bit = sum % 2;
        carry = sum / 2;
        t = t->prev;
    }

    cout << "\\n2's complement: ";
    for (t = head; t != NULL; t = t->next)
        cout << t->bit;

    return 0;
}
