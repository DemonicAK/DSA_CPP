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
class Node
{
public:
  int data;
  Node *left, *right;
  Node()
  {
    this->data = 0;
    left = NULL;
  }
  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
  Node(int data, Node *left, Node *right)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

/*
it is DFS traversal
*/

// preorder traversal
void preorder(Node *temp)
{
  if (temp != NULL)
  {
    cout << " " << temp->data;
    preorder(temp->left);
    preorder(temp->right);
  }
}

// //inorder traversal
void inorder(Node *temp)
{

  if (temp != NULL)
  {
    inorder(temp->left);
    cout << " " << temp->data;
    inorder(temp->right);
  }
}

// postorder traversal
void postorder(Node *temp)
{

  if (temp != NULL)
  {
    postorder(temp->left);
    postorder(temp->right);
    cout << " " << temp->data;
  }
}

// height of tree
int height(Node *root)
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
void levelorder(Node *root)
{ // it is also called breadth first search
  //  space complexity is O(n)

  if (root == NULL)
  {

    return;
  }
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *n = q.front();
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
void level_traversal(Node *root, int k)
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

// left view

void leftview_util(Node *root, int level, int *maxlevel)
{

  if (!root)
    return;

  if (*maxlevel < level)
  {
    cout << root->data << " ";
    *maxlevel = level;
  }
  leftview_util(root->left, level + 1, maxlevel);
  leftview_util(root->right, level + 1, maxlevel);
}

void leftview(Node *root)
{

  int maxlevel = 0;
  leftview_util(root, 0, &maxlevel);
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

  Node *root = new Node(7);

  // Node value 7
  root->left = new Node(3);
  root->right = new Node(9);

  // Node value 3
  root->left->left = new Node(1);
  root->left->right = new Node(5);

  // Node value 9
  root->right->left = new Node(8);
  root->right->right = new Node(10);

  // Node value 8
  root->right->left->left = new Node(4);
  root->right->left->right = new Node(6);

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