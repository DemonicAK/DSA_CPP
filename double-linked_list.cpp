


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

 
 
 
int main()
{
 node* head=new node(89);
 
 
 
    return 0;
}