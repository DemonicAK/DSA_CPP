#include "bits/stdc++.h"
#define max 99999999
using namespace std;

class node
{
public:
    int data;
    int pri;
    node *next;

    node(int Data, int p_num)     //p_num-> priority number
    {
        data = Data;
        pri = p_num;
        next = NULL;
    }
};
int length(node *head);
void insert(node *&head, int val, int pri);
void remove(node *&head);
int findpos(node *head, int val);
int valueat(node *head, int pos);

void insert(node *&head, int val, int pri)
{

    node *n = new node(val, pri);
    node *temp = head;

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        if (n->pri < head->pri)
        {
            n->next = head;
            head = n;
        }
        else if (temp->next == NULL)
        {
            temp->next = n;
        }
        else
        {
            while (temp->next->pri < n->pri )
            {
                    temp = temp->next;
                if(temp->next==NULL){
                    break;
                }
            
            }
            n->next = temp->next;
            temp->next = n;
        }
    }
}

void remove(node *&head)
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
        cout << ptr->data << "|" << ptr->pri << "->";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insert(head, 9, 1);

    insert(head, 10, 2);
    insert(head, 11, 3);
    insert(head, 12,4);
    insert(head, 14,5);
    display(head);

    insert(head, 78,98);
    insert(head, 79,9);
    remove(head);
    remove(head);
     display(head);


    return 0;
}
