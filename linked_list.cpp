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
int position(node *head, int val);
int value(node *head, int pos);
void insert(node *&head, int val, int pos = max);
void delet(node *&head, int pos = max);
void del_value(node *&head, int val);
node *reverse(node *head);

void insert(node *&head, int val, int pos)
{

    if (pos >= length(head) + 1)
    {
        pos = length(head) + 1;
    }

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        if (pos == 1)
        {

            n->next = head;
            head = n;
        }
        else
        {
            node *temp = head;
            int temppos = 1;
            while (temppos != pos - 1)
            {
                temp = temp->next;
                temppos++;
            }
            node *saver = temp->next;
            temp->next = n;
            n->next = saver;
        }
    }
}

void delet(node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    cout << pos << "\n";

    if (pos >= length(head))
    {
        pos = length(head);
    }
    if (pos == 1)
    {
        // del_head(head)
        node *v = head;
        head = head->next;
        delete v;
    }
    else
    {
        node *temp = head;
        int temppos = 1;
        while (temppos != pos - 1)
        {
            temp = temp->next;
            temppos++;
        }
        node *v = temp->next;
        temp->next = temp->next->next;
        delete v;
    }
}
void del_value(node *&head, int val)
{
    int ps = position(head, val);
    if (ps != -1)
        delet(head, ps);
}
node *reverse(node *head)
{
    node *rev = NULL;
    node *temp = head;
    while (temp)
    {
        insert(rev, temp->data, 1);
        temp = temp->next;
    }
    return rev;
}

int value(node *head, int pos)
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

int position(node *head, int val)
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

node *reverse1(node *head)
{
    node *current= head;
    node *nxt = NULL;
    node *pre = NULL;

    while (current)
    {
        nxt = current->next; // setting as processing will loss its refrence
        current->next = pre;  // changing the pointing node
        pre = current;  // reseeting the head

        current= nxt;    // moving forward

       
    }
    return pre;
}

void display(node *head)
{
    node *ptr = head;
    // ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insert(head, 9);
    insert(head, 10);
    insert(head, 11);
    insert(head, 12);
    insert(head, 14);
    display(head);

    insert(head, 78, 7);
    display(head);
    delet(head);
    // del_value(head,78);
    cout << position(head, 78) << "\n";
    // delet(head,position(head,78));
    display(head);



    node *head1 = NULL;
    head1 = reverse1(head);
    display(head1);

    return 0;
}