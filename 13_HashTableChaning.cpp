#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    const int SIZE = 10;
    Node* table[SIZE] = {NULL};
    int ch, x, index;

    do {
        cout << "\\n1.Insert 2.Search 3.Display 4.Exit\\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter number (non-negative): ";
            cin >> x;

            if (x < 0) {
                cout << "Enter a non-negative number";
                continue;
            }

            index = x % SIZE;
            Node* t = new Node{x, table[index]};
            table[index] = t;
            cout << "Inserted";
        }
        else if (ch == 2) {
            cout << "Enter number to search: ";
            cin >> x;

            if (x < 0) {
                cout << "Invalid number";
                continue;
            }

            index = x % SIZE;
            Node* t = table[index];

            while (t != NULL && t->data != x)
                t = t->next;

            cout << (t != NULL ? "Found" : "Not Found");
        }
        else if (ch == 3) {
            for (int i = 0; i < SIZE; i++) {
                cout << i << ": ";
                for (Node* t = table[i]; t != NULL; t = t->next)
                    cout << t->data << " -> ";
                cout << "NULL\\n";
            }
        }
        else if (ch != 4) {
            cout << "Invalid choice";
        }
    } while (ch != 4);

    return 0;
}
