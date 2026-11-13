#include <iostream>
#include <string>
using namespace std;

struct Node {
    int bit;
    Node *prev, *next;
};

Node* makeList(string s) {
    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < s.length(); i++) {
        Node* t = new Node{s[i] - '0', tail, NULL};
        if (head == NULL)
            head = t;
        else
            tail->next = t;
        tail = t;
    }
    return head;
}

bool isBinary(string s) {
    if (s.empty())
        return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0' && s[i] != '1')
            return false;
    }
    return true;
}

int main() {
    string a, b, ans = "";

    cout << "Enter two binary numbers: ";
    cin >> a >> b;

    if (!isBinary(a) || !isBinary(b)) {
        cout << "Invalid binary number";
        return 0;
    }

    Node *x = makeList(a);
    Node *y = makeList(b);

    while (x != NULL && x->next != NULL)
        x = x->next;
    while (y != NULL && y->next != NULL)
        y = y->next;

    int carry = 0;
    while (x != NULL || y != NULL || carry) {
        int sum = carry;

        if (x != NULL) {
            sum += x->bit;
            x = x->prev;
        }
        if (y != NULL) {
            sum += y->bit;
            y = y->prev;
        }

        ans = char('0' + sum % 2) + ans;
        carry = sum / 2;
    }

    cout << "Addition = " << ans;
    return 0;
}
