#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int prn;
    string name;
    Node *next;
};

Node *addPresident(Node *head, int prn, string name)
{
    Node *t = new Node{prn, name, head};
    return t;
}

Node *addMember(Node *head, int prn, string name)
{
    Node *t = new Node{prn, name, NULL};
    if (head == NULL)
        return t;

    Node *p = head;
    while (p->next != NULL && p->next->next != NULL)
        p = p->next;

    t->next = p->next;
    p->next = t;
    return head;
}

Node *addSecretary(Node *head, int prn, string name)
{
    Node *t = new Node{prn, name, NULL};
    if (head == NULL)
        return t;

    Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = t;
    return head;
}

int countMembers(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void displayMembers(Node *head)
{
    if (head == NULL)
        cout << "Club is empty\\n";
    while (head != NULL)
    {
        cout << "PRN: " << head->prn << ", Name: " << head->name << endl;
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    int choice, prn;
    string name;

    do
    {
        cout << "\\n1. Add President\\n2. Add Member\\n3. Add Secretary";
        cout << "\\n4. Display Members\\n5. Count Members\\n6. Exit\\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            cout << "Enter PRN and name: ";
            cin >> prn >> ws;
            getline(cin, name);

            if (choice == 1)
            {
                if (head != NULL)
                    cout << "President already exists\\n";
                else
                    head = addPresident(head, prn, name);
            }
            else if (choice == 2)
            {
                head = addMember(head, prn, name);
            }
            else
            {
                head = addSecretary(head, prn, name);
            }
        }
        else if (choice == 4)
        {
            displayMembers(head);
        }
        else if (choice == 5)
        {
            cout << "Total members = " << countMembers(head) << endl;
        }
        else if (choice != 6)
        {
            cout << "Invalid choice\\n";
        }
    } while (choice != 6);

    return 0;
}
