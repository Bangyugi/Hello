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

int size(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void earase(node *&head, int k)
{
    if (k < 1 || k > size(head))
        return;
    if (k == 1)
    {
        if (head == NULL)
            return;
        node *remove = head;
        head = head->next;
        delete remove;
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

void xoanode(node *&head, int x)
{
    node *temp1 = NULL;
    node *temp2 = head;
    while (temp2 != NULL)
    {
        if (temp2->data == x)
        {
            if (temp1 == NULL)
            {
                head = temp2->next;
                temp2 = head;
            }
            else
            {
                temp1->next = temp2->next;
                temp2 = temp1->next;
            }
        }
        else
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
}

void PushBack(node *&head, int x)
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

void review(node *head)
{
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
    int n, x, m;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        PushBack(head, m);
    }
    xoanode(head, x);
    if (head == NULL)
    {
        cout << "EMPTY";
    }
    else
    {
        review(head);
    }
}
