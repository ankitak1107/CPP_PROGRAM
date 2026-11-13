#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createList(int n)
{
    Node *head = NULL, *tail = NULL;

    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        Node *t = new Node{x, NULL};

        if (head == NULL)
            head = tail = t;
        else
        {
            tail->next = t;
            tail = t;
        }
    }
    return head;
}

int main()
{
    int n, m;

    cout << "Enter size of first list (0-100): ";
    cin >> n;
    if (n < 0 || n > 100)
    {
        cout << "Invalid size";
        return 0;
    }
    cout << "Enter first list values: ";
    Node *a = createList(n);

    cout << "Enter size of second list (0-100): ";
    cin >> m;
    if (m < 0 || m > 100)
    {
        cout << "Invalid size";
        return 0;
    }
    cout << "Enter second list values: ";
    Node *b = createList(m);

    if (a == NULL)
    {
        a = b;
    }
    else
    {
        Node *t = a;
        while (t->next != NULL)
            t = t->next;
        t->next = b;
    }

    cout << "Concatenated list: ";
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }

    return 0;
}
