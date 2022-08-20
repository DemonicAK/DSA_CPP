#include "bits/stdc++.h"
#define max 99999999
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int Data)
    {
        data = Data;
        next = NULL;
    }
};
int length(node *head);
void push(node *&head, int val);
void pop(node *&head);
int findpos(node *head, int val);
int valueat(node *head, int pos);

void push(node *&head, int val)
{
    int pos = length(head) + 1;

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
    }
    else
    {

        node *temp = head;
        // int temppos = 1;
        while (temp->next)
        {
            temp = temp->next;
            // temppos++;
        }
        // node *saver = temp->next;
        temp->next = n;
        // n->next = saver;
    }
}

void pop(node *&head)
{
    int pos = 1;
    if (head == NULL)
    {
        return;
    }

    if (pos == 1)
    {
        // del_head(head);
        node *v = head;
        head = head->next;
        delete v;
    }
}
int valueat(node *head, int pos)
{
    node *temp = head;
    int temppos = 1;
    while (temppos != pos)
    {
        temppos++;
        temp = temp->next;
    }
    return temp->data;
}

int findpos(node *head, int val)
{

    node *temp = head;
    int pos = 1;
    while (temp)
    {
        if (val == temp->data)
        {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1;
}

int length(node *head)
{
    node *ptr = head;
    // ptr = head;
    int count = 0;
    while (ptr)
    {
        // cout << ptr->data << " ";
        count++;
        ptr = ptr->next;
    }
    return count;
}

void display(node *head)
{
    node *ptr = head;
    // ptr = head;
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    push(head, 9);
    push(head, 10);
    push(head, 11);
    push(head, 12);
    push(head, 14);
    display(head);

    push(head, 78);

    display(head);
    pop(head);
    cout << findpos(head, 78);
    cout<<head->data;
    return 0;
}