#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    stack<char> st;

    cout << "Enter expression: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                cout << "Not Balanced";
                return 0;
            }

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    if (st.empty())
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}

 