#include "bits/stdc++.h"
#define inf 99999999
using namespace std;


class node{  
    public:
    int data;
    node* left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preorder(struct node *temp)
{
  if (temp != NULL) {
    cout << " " << temp->data;
    preorder(temp->left);
    preorder(temp->right);
  }
}
void inorder(struct node *temp) {

    inorder(temp->left);

  if (temp != NULL) {
    cout << " " << temp->data;


    inorder(temp->right);
  }

}
void postorder(struct node *temp) {
    postorder(temp->left);

    postorder(temp->right);

  if (temp != NULL) {
    cout << " " << temp->data;

  }

}





int main(){

node * root =new node(7);
// cout<<"it is root value:"<<root->data<<"\n";
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);







preorder(root);
  cout<<"\n";

    return 0;
}