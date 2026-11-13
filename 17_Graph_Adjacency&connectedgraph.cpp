#include <iostream>
using namespace std;

int cost[20][20], visited[20], n;

void depthFirstSearch(int city) {
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        // A positive cost means that a flight route exists.
        if (cost[city][i] > 0 && visited[i] == 0)
            depthFirstSearch(i);
    }
}

int main() {
    cout << "Enter number of cities (1-20): ";
    cin >> n;
    if (n < 1 || n > 20) {
        cout << "Invalid number of cities";
        return 0;
    }

    cout << "Enter weighted adjacency matrix (0 if no flight):\\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] < 0) {
                cout << "Cost cannot be negative";
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) visited[i] = 0;

    depthFirstSearch(0);

    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) connected = false;
    }

    if (connected)
        cout << "Graph is connected";
    else
        cout << "Graph is not connected";

    return 0;
}

 