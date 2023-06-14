#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *makeNode(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
// hàm duyệt DSLK
void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int dem(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void themcuoi(node *&head, int x)
{
    node *newNode = makeNode(x);
    node *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void themdau(node *&head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

void themgiua(node *&head, int x, int k)
{
    // muốn chèn vào vị trí k phải đến vị trí k-1
    if (k < 1 || k > dem(head) + 1)
        return;
    node *newNode = makeNode(x);
    node *temp = head;
    for (int i = 1; i <= k - 2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void xoadau(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *xoa = head;
    head = head->next;
    delete xoa;
}

void xoacuoi(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
}

int main()
{
    node *head = NULL;
    // head = makeNode(1);
    // cout << head << "\n";
    // cout << head->data << "\n";
    // cout << head->next << "\n";
    // node *X = makeNode(100);
    // head->next = X;
    // node *Y = makeNode(1000);
    // X->next = Y;
    // duyet(head);
    // cout << dem(head);
    for (int i = 1; i <= 5; i++)
    {
        themcuoi(head, i);
    }
    themdau(head, 0);
    themgiua(head, 7, 3);
    duyet(head);
}