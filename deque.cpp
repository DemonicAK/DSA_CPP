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

void front_insert(node *&head, int val)
{
    // int pos = 1;

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}
void end_insert(node *&head, int val)
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

void front_del(node *&head)
{
    // int pos=1;
    if (head == NULL)
    {
        return;
    }

    // del_head(head);
    node *v = head;
    head = head->next;
    delete v;
}
void end_del(node *&head)
{
    node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    node *tt = temp->next;
    temp->next = NULL;
    delete tt;
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
    front_insert(head, 9);
    front_insert(head, 10);
    front_insert(head, 11);
    front_insert(head, 12);
    front_insert(head, 14);
    display(head);

    front_insert(head, 78);

    display(head);
    front_del(head);
    cout << findpos(head, 78);
    return 0;
}