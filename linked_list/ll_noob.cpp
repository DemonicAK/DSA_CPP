

#include <iostream>
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








void insert_at_begin(node *&head, int val)
{

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

void insert_at_end(node *head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}


void add_at_pos(node *&head, int pos, int val)
{
    node *ne = new node(val);
    if (pos == 1)
    {
        insert_at_begin(head, pos);
    }
    else if (pos == (length(head) + 1))
    {
        insert_at_end(head, val);
    }
    else
    {
        node *temp = head;
        int i = 1;
        while (i != pos - 1)
        {
            temp = temp->next;
            i++;
        }
        node *saver = temp->next;
        temp->next = ne;
        ne->next = saver;
    }
}

void del_at(node *&head, int pos=max)
{
     if (head == NULL)
    {
        return;
    }

    if (pos==max){
        pos=length(head);
    }
    if (pos == 1)
    {
        // del_head(head);
        node *v = head->next;
        head = head->next;
        delete v;
    }
    else
    {
        node *temp = head;
        int i = 1;
        while (i != pos - 1)
        {
            temp = temp->next;
            i++;
        }
        node *v = temp->next;
        temp->next = temp->next->next;
        delete v;
    }
}

void del_by_val(node *&head, int val)

{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        del_head(head);
    }
    if (val == head->data)
    { // del_head(head);
        node *v = head;
        head = head->next;
        delete v;
    }

    else
    {

        node *temp = head;
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        node *v = temp->next;
        temp->next = temp->next->next;
        delete v;
    }
}
void del_head(node *&head)
{
    node *v = head->next;
    head = head->next;
    delete v;
}


int valueat(node* head,int pos){
    node* temp=head;
    int i=1;
    while (i!=pos){i++;temp=temp->next;}
    return temp->data;
}

int findpos(node* head,int val){

    node* temp=head;
    int pos=1,flag=0;
    while(val!=temp->data or temp==NULL){
        pos++;
        temp=temp->next;
    }if (temp==NULL){pos=-1;}
    return pos;
}


int length(node *head)
{
    node *ptr=head;
    // ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        // cout << ptr->data << " ";
        count++;
        ptr = ptr->next;
    }
    return count;
}



void display(node *head)
{
    node *ptr=head;
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
    node *head = new node(89);
    insert_at_end(head, 90);
    insert_at_end(head, 91);
    insert_at_end(head, 92);
    insert_at_end(head, 93);
    display(head);

    insert_at_begin(head, 8);
    display(head);

    del_at(head, 2);
    display(head);

    del_by_val(head, 8);
    display(head);
    
    add_at_pos(head, 2, 56);
    display(head);


   cout<< findpos(head,56)<<endl;
   cout<< valueat(head,2)<<endl;




    return 0;
}