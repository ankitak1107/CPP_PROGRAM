#include <iostream>
#include <algorithm>
using namespace std;

// Linear Search
int linearSearch(int a[], int n, int key, int &c) {
    c = 0;

    for (int i = 0; i < n; i++) {
        c++;

        if (a[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int a[], int n, int key, int &c) {
    int low = 0, high = n - 1;
    c = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        c++;

        if (a[mid] == key)
            return mid;

        if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {
    int a[100], n, choice, key, c, pos;

    cout << "Enter number of students (1-100): ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid size";
        return 0;
    }

    cout << "Enter roll numbers in any order: ";

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    do {
        cout << "\n1. Linear Search";
        cout << "\n2. Binary Search";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter roll number to search: ";
            cin >> key;

            if (choice == 1) {
                pos = linearSearch(a, n, key, c);
                cout << "Linear Search: ";
            }
            else {
                int sorted[100];

                for (int i = 0; i < n; i++) {
                    sorted[i] = a[i];
                }

                sort(sorted, sorted + n);

                pos = binarySearch(sorted, n, key, c);
                cout << "Binary Search: ";
            }

            if (pos == -1)
                cout << "Student not found\n";
            else
                cout << "Student found\n";

            cout << "Comparisons = " << c << endl;
        }
        else if (choice != 3) {
            cout << "Invalid choice";
        }

    } while (choice != 3);

    return 0;
}