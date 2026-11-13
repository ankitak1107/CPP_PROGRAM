#include <iostream>
using namespace std;

void selectionSort(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIndex]) minIndex = j;

        float temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main() {
    float a[100];
    int n;
    cout << "Enter number of students (1-100): ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid size";
        return 0;
    }

    cout << "Enter first-year percentages: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    selectionSort(a, n);

    cout << "Ascending order: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    cout << "\\nTop scores: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << a[i] << " ";

    return 0;
}

 