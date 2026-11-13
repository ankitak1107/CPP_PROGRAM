#include <iostream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 11; // Prime table size
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
            int i = 0, pos;

            while (i < SIZE) {
                pos = (index + i * i) % SIZE;
                if (phone[pos] == -1)
                    break;
                if (phone[pos] == key)
                    break;
                i++;
            }

            if (i == SIZE) {
                cout << "No available position in quadratic probe sequence";
            }
            else if (phone[pos] == key) {
                cout << "Phone number already exists";
            }
            else {
                phone[pos] = key;
                name[pos] = nm;
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
            int i = 0, pos;
            bool found = false;

            while (i < SIZE) {
                pos = (index + i * i) % SIZE;
                if (phone[pos] == -1)
                    break;
                if (phone[pos] == key) {
                    found = true;
                    break;
                }
                i++;
            }

            if (found)
                cout << "Found: " << name[pos];
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

 