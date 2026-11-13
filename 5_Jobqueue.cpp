#include <iostream>
using namespace std;

const int SIZE = 100;
int q[SIZE], frontIndex = 0, rearIndex = -1;

void addJob(int job)
{
    if (rearIndex == SIZE - 1)
    {
        cout << "Queue is full\\n";
        return;
    }
    q[++rearIndex] = job;
    cout << "Job added\\n";
}

void deleteJob()
{
    if (frontIndex > rearIndex)
    {
        cout << "Queue is empty\\n";
        return;
    }
    cout << "Deleted job: " << q[frontIndex++] << endl;

    if (frontIndex > rearIndex)
    {
        frontIndex = 0;
        rearIndex = -1;
    }
}

void displayQueue()
{
    if (frontIndex > rearIndex)
    {
        cout << "Queue is empty\\n";
        return;
    }
    cout << "Jobs in queue: ";
    for (int i = frontIndex; i <= rearIndex; i++)
        cout << q[i] << " ";
    cout << endl;
}

int main()
{
    int choice, job;
    do
    {
        cout << "\\n1. Add Job\\n2. Delete Job\\n3. Display Queue\\n4. Exit\\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter job number: ";
            cin >> job;
            addJob(job);
        }
        else if (choice == 2)
        {
            deleteJob();
        }
        else if (choice == 3)
        {
            displayQueue();
        }
        else if (choice != 4)
        {
            cout << "Invalid choice\\n";
        }
    } while (choice != 4);

    return 0;
}
