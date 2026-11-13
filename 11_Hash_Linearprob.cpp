#include <iostream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 10;
    int phone[SIZE], key, index, choice;
    string name[SIZE];

    for (int i = 0; i < SIZE; i++)
        phone[i] = -1;

    do {
        cout << "\\n1.Insert 2.Search 3.Display 4.Exit\\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string nm;
            cout << "Enter client name: ";
            cin >> ws;
            getline(cin, nm);
            cout << "Enter phone number: ";
            cin >> key;

            if (key < 0) {
                cout << "Enter a non-negative phone number";
                continue;
            }

            index = key % SIZE;
            int i = 0;

            while (i < SIZE && phone[(index + i) % SIZE] != -1)
                i++;

            if (i == SIZE) {
                cout << "Hash table full";
            }
            else {
                phone[(index + i) % SIZE] = key;
                name[(index + i) % SIZE] = nm;
                cout << "Record inserted";
            }
        }
        else if (choice == 2) {
            cout << "Enter phone number: ";
            cin >> key;

            if (key < 0) {
                cout << "Invalid phone number";
                continue;
            }

            index = key % SIZE;
            int i = 0;

            while (i < SIZE &&
                   phone[(index + i) % SIZE] != -1 &&
                   phone[(index + i) % SIZE] != key)
                i++;

            if (i < SIZE && phone[(index + i) % SIZE] == key)
                cout << "Found: " << name[(index + i) % SIZE];
            else
                cout << "Not found";
        }
        else if (choice == 3) {
            for (int i = 0; i < SIZE; i++) {
                if (phone[i] != -1)
                    cout << i << " " << name[i] << " " << phone[i] << endl;
            }
        }
        else if (choice != 4) {
            cout << "Invalid choice";
        }
    } while (choice != 4);

    return 0;
}

 