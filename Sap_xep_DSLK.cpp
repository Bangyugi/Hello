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

void PushBack(node *&head, int x)
{
    node *newnode = makenode(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void show(node *head)
{
    if (head == NULL)
    {
        cout << "EMPTY";
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        PushBack(head, x);
    }
    show(head);
}