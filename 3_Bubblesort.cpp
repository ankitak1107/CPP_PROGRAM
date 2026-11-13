#include <iostream>
using namespace std;

int main() {
    int n;
    float a[100], temp;

    cout << "Enter number of students (1-100): ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid number of students";
        return 0;
    }

    cout << "Enter percentages: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Ascending order: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\\nTop scores: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << a[i] << " ";

    return 0;
}
 