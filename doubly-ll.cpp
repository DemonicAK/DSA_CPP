


#include<iostream>
#include<stdlib.h>
using namespace std;
  



class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        data=val;
        prev=NULL;
        next=NULL;

    }
};

int length(node *head);

void insert(node *&head, int val, int pos){
    node* temp=new node(val);
    node* itr=head;
    int siz=length(head);

    if (head ==NULL){
        head=temp;
    }
    else if  (pos=siz+1){
        while(itr->next){
            itr=itr->next;

        }
        itr->next=temp;
        temp->prev=itr;

    }
    else if (pos==1){
        temp->next=head;
        head->prev=temp;
        head=temp;

    }
    else{
        while(itr){cout<<5;}
    }

    
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
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

 
 
 
int main()
{
 node* head=new node(89);
    int siz=length(head);
 insert(head,49,length(head)+1);
 insert(head,98,length(head)+1);
 insert(head,78,length(head)+1);
 insert(head,45,length(head)+1);
 insert(head,99,length(head)+1);
 insert(head,29,length(head)+1);

display(head);
 
 
    return 0;
}