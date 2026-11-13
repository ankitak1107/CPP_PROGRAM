#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

Node* addEnd(Node* head, int prn, string name) {
    Node* t = new Node{prn, name, NULL};
    if (head == NULL) return t;
    Node* p = head;
    while (p->next != NULL) p = p->next;
    p->next = t;
    return head;
}

Node* deletePresident(Node* head) {
    if (head == NULL) {
        cout << "Club is empty\\n";
        return head;
    }
    Node* t = head;
    head = head->next;
    delete t;
    cout << "President deleted\\n";
    return head;
}

Node* deleteSecretary(Node* head) {
    if (head == NULL) {
        cout << "Club is empty\\n";
        return head;
    }
    if (head->next == NULL) {
        delete head;
        cout << "Secretary/member deleted\\n";
        return NULL;
    }
    Node* p = head;
    while (p->next->next != NULL) p = p->next;
    delete p->next;
    p->next = NULL;
    cout << "Secretary deleted\\n";
    return head;
}

Node* deleteMember(Node* head, int prn) {
    Node *p = head, *prev = NULL;
    while (p != NULL && p->prn != prn) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        cout << "Member not found\\n";
        return head;
    }
    if (prev == NULL) head = p->next;
    else prev->next = p->next;
    delete p;
    cout << "Member deleted\\n";
    return head;
}

int countMembers(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void displayMembers(Node* head) {
    if (head == NULL) cout << "Club is empty\\n";
    while (head != NULL) {
        cout << "PRN: " << head->prn << ", Name: " << head->name << endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int choice, prn;
    string name;

    do {
        cout << "\\n1. Add Member\\n2. Delete President\\n3. Delete Secretary";
        cout << "\\n4. Delete Member by PRN\\n5. Count Members\\n6. Display\\n7. Exit\\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter PRN and name: ";
            cin >> prn >> ws;
            getline(cin, name);
            head = addEnd(head, prn, name);
        } else if (choice == 2) {
            head = deletePresident(head);
        } else if (choice == 3) {
            head = deleteSecretary(head);
        } else if (choice == 4) {
            cout << "Enter PRN: ";
            cin >> prn;
            head = deleteMember(head, prn);
        } else if (choice == 5) {
            cout << "Total members = " << countMembers(head) << endl;
        } else if (choice == 6) {
            displayMembers(head);
        } else if (choice != 7) {
            cout << "Invalid choice\\n";
        }
    } while (choice != 7);

    return 0;
}

 