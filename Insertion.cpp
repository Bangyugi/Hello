#include <bits/stdc++.h>
using namespace std;

struct sinhvien
{
    string msv;
    string name;
    double gpa;
    void nhap()
    {
        cin.ignore();
        getline(cin, msv);
        getline(cin, name);
        cin >> gpa;
    }
    void xuat()
    {
        cout << msv << " " << name << " " << fixed << setprecision(2) << gpa << "\n";
    }
};

struct node
{
    sinhvien data;
    node *next;
};

node *makenode(sinhvien x)
{
    node *newnode = new node;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

int size(node *head)
{
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void pushFront(node *&head, sinhvien x)
{
    node *newnode = makenode(x);
    newnode->next = head;
    head = newnode;
}

void pushBack(node *&head, sinhvien x)
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

void insert(node *&head, int k, sinhvien x)
{
    node *newnode = makenode(x);
    node *temp = head;
    if (k == 1)
    {
        pushFront(head, x);
        return;
    }
    if (k == size(head) + 1)
    {
        pushBack(head, x);
        return;
    }
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void duyet(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        temp->data.xuat();
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    int n, k;
    int thaotac;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> thaotac;
        if (thaotac == 1)
        {
            sinhvien x;
            x.nhap();
            pushFront(head, x);
        }
        else if (thaotac == 2)
        {
            sinhvien x;
            x.nhap();
            pushBack(head, x);
        }
        else
        {
            cin >> k;
            sinhvien x;
            x.nhap();
            insert(head, k, x);
        }
    }
    duyet(head);
}