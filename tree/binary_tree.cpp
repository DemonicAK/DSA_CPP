#include "bits/stdc++.h"
#define inf 99999999
using namespace std;

/*
functions included:

1. preorder
2. inorder
3. postorder
4. levelorder
5. height
6. diameter
7. mirror
8. print all paths
9. print all paths sum
10. print all paths sum equal to k



*/

// Node structure
class node
{
public:
  int data;
  node *left;
  node *right;
  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

/*
it is DFS traversal
*/

// preorder traversal
void preorder(struct node *temp)
{
  if (temp != NULL)
  {
    cout << " " << temp->data;
    preorder(temp->left);
    preorder(temp->right);
  }
}

// //inorder traversal
void inorder(struct node *temp)
{

  if (temp != NULL)
  {
    inorder(temp->left);
    cout << " " << temp->data;
    inorder(temp->right);
  }
}

// postorder traversal
void postorder(struct node *temp)
{

  if (temp != NULL)
  {
    postorder(temp->left);
    postorder(temp->right);
    cout << " " << temp->data;
  }
}

// height of tree
int height(node *root)
{
  if (root == NULL)
  { // it is base case
    return 0;
  }
  int lheight = height(root->left);
  int rheight = height(root->right);
  return max(lheight, rheight) + 1;
}

/*
from here BFS traversal starts
*/

// level order traversal
void levelorder(node *root)
{ // it is also called breadth first search
  //  space complexity is O(n)

  if (root == NULL)
  {

    return;
  }
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    node *n = q.front();
    q.pop();

    if (n != NULL)
    {
      cout << n->data << " ";
      if (n->left)
      {
        q.push(n->left);
      }
      if (n->right)
      {
        q.push(n->right);
      }
    }

    else if (!q.empty())
    {
      cout << "\n"; // it tells that the level is over
      q.push(NULL);
    }
  }
}

// level order traversal of paerticular level
void level_traversal(node *root, int k)
{
  if (root == NULL)
  {
    return;
  }
  if (k == 1)
  {
    cout << root->data << " ";
  }
  level_traversal(root->left, k - 1);
  level_traversal(root->right, k - 1);
}



//left view

void leftview_util(node* root,int level,int* maxlevel){

if(!root) return;


if (*maxlevel<level){
cout<<root->data<<" ";
*maxlevel=level;
}
leftview_util(root->left,level+1,maxlevel);
leftview_util(root->right,level+1,maxlevel);


}


void leftview(node* root){

int maxlevel=0;
leftview_util(root,0,&maxlevel);

}























/*

tree taken as input
         7
       /   \
      3     9
     / \   / \
    1  5  8  10
         / \
        4   6

*/

int main()
{

  node *root = new node(7);

  // node value 7
  root->left = new node(3);
  root->right = new node(9);

  // node value 3
  root->left->left = new node(1);
  root->left->right = new node(5);

  // node value 9
  root->right->left = new node(8);
  root->right->right = new node(10);

  // node value 8
  root->right->left->left = new node(4);
  root->right->left->right = new node(6);

  cout << "preorder traversal" << endl;
  preorder(root);
  cout << "\n";

  cout << "inorder traversal" << endl;
  inorder(root);
  cout << "\n";

  cout << "postorder traversal" << endl;
  postorder(root);
  cout << "\n";

  cout << "levelorder traversal" << endl;
  levelorder(root);
  cout << "\n";


  cout << "left view" << endl;
  leftview(root);
  cout << "\n";

  cout << "height of tree"
       << " " << height(root) << endl;

  return 0;
}