#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *makenode(int x)
{
    node *newnode = new node;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void PushFront(node *&head, int x)
{
    node *newnode = makenode(x);
    node *temp = head;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = temp;
    head = newnode;
}

void PopFront(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    head = temp->next;
    delete temp;
}

void ShowNode(node *head)
{
    if (head == NULL)
    {
        cout << "EMPTY"
             << "\n"
             << "\n";
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    node *head = NULL;
    int n, x;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            PushFront(head, x);
        }
        else if (s == "pop")
        {
            PopFront(head);
        }
        else if (s == "show")
        {
            ShowNode(head);
        }
        s.clear();
    }
}