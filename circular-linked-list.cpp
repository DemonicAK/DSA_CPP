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
        next = this;
    }
};
int length(node *tail);
int position(node *tail, int val);
int value(node *tail, int pos);
void insert(node *&tail, int val, int pos = max);
void delet(node *&tail, int pos = max);
void del_value(node *&tail, int val);
void display(node *tail);
node *reverse(node *tail);

void insert(node *&tail, int val, int pos)
{
    int len = length(tail);
    if (pos >= len)
    {
        pos = len + 1;
    }
    node *n = new node(val);
    node *temp = tail;
    if (tail == NULL)
    {
        tail = n;
        // tail->next = tail;
    }
    // else if(pos==len+1 or pos==1 ){

    // }
    else
    {

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;

        if (pos == len + 1) // temp == tail &
        {
            tail = tail->next;
        }

        // return tail;
    }
}
void delet(node *&tail, int pos )
{int len=length(tail);
int flag=1;
    node *temp = tail;


    if(pos>=len){
        pos=len;
    }
    if(tail==NULL){return;}
    else{
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if(temp->next==tail){flag=0;}
        temp->next=temp->next->next;
        if (flag==0){tail=temp;}

    }

}
// node *reverse(node *tail)
// {
//     node *ptr = tail;
//     node*neew;
//     // ptr = tail;
//     do
//     {
//         ptr = ptr->next;
//         insert(neew,ptr->data,1);
//         // cout << ptr->data << " ";
//         // ptr = ptr->next;
//     } while (ptr != tail);

//     // cout << endl;
//     return neew;
// }

int length(node *tail)
{
    if (tail == NULL)
    {
        return 0;
    }
    node *ptr = tail;
    // ptr = tail;
    int count = 0;
    do
    {
        // cout << ptr->data << " ";
        count++;
        ptr = ptr->next;
    } while (ptr != tail);

    // cout << endl;
    return count;
}

void display(node *tail)
{
    node *ptr = tail;
    // ptr = tail;
    do
    {
        ptr = ptr->next;
        cout << ptr->data << " ";
        // ptr = ptr->next;
    } while (ptr != tail);

    cout << endl;
}

int main()
{

    node *tail = NULL;
    insert(tail, 9);
    insert(tail, 6);
    insert(tail, 8);
    insert(tail, 7);
// delet(tail,4);
    display(tail);
delet(tail,7);
    display(tail);
    
    node *tail1 = NULL;
tail1=reverse(tail);
display(tail1);


    return 0;
}