#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

// Create a new node
node *makenode(int x)
{
    node *newnode = new node;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

// review node
void review(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// count node
int size(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

// insert at front
void pushFront(node *&head, int x)
{
    node *newnode = makenode(x);
    newnode->next = head;
    head = newnode;
}

// insert at back
void pushBack(node *&head, int x)
{
    node *newnode = makenode(x);
    node *temp = head;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

// insert at position k
void insert(node *&head, int k, int x)
{
    if (k < 1 || k > size(head))
    {
        cout << "Vi tri chen khong hop le!";
        return;
    }
    if (k == 1)
    {
        pushFront(head, x);
        return;
    }
    node *temp = head;
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
    node *newnode = makenode(x);
    newnode->next = temp->next;
    temp->next = newnode;
}

// remove at front
void popFront(node *&head)
{
    if (head == NULL)
        return;
    node *remove = head;
    head = head->next;
    delete remove;
}

// remove at back
void popBack(node *&head)
{
    node *temp = head;
    if (head == NULL)
        return;
    if (temp->next == NULL)
    {
        head = NULL;
        delete temp;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *remove = temp->next;
    temp->next = NULL;
    delete remove;
}

// remove at position k
void earase(node *&head, int k)
{
    if (k < 1 || k > size(head))
        return;
    if (k == 1)
    {
        popFront(head);
        return;
    }
    node *temp = head;
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
    node *remove = temp->next;
    temp->next = remove->next;
    delete remove;
}

int main()
{
    node *head = NULL;
    head = makenode(2);
    node *x = makenode(3);
    head->next = x;
    node *y = makenode(4);
    x->next = y;
    pushFront(head, 1);
    pushBack(head, 6);
    insert(head, 5, 5);
    review(head);
    cout << "\n";
    earase(head, 4);
    popFront(head);
    popBack(head);
    review(head);
}
