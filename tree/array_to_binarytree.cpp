#include <bits/stdc++.h> // Include every standard library
using namespace std;

// Following is the class structure of the Node class:

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


void preorder(Node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}

Node *createTree(vector<int> &arr)
{
    // Write your code here.
    // Check if the vector is empty
    if (arr.empty())
    {
        return nullptr;
    }

    // Create a queue to store nodes
    queue<Node *> q;

    // Create a root node with the first element of the vector
    Node *root = new Node(arr[0]);

    // Enqueue the root node
    // q.push(root);
    Node *parent = root;

    // Iterate over the remaining elements of the vector
    for (int i = 1; i < arr.size(); i++)
    {
        // Create a new node with the current element
        Node *newNode = new Node(arr[i]);
        q.push(newNode);
        if (!parent->left)   
              parent->left = newNode;
           // If the left child of the parent node is empty, make the new node the left child
        else if (!parent->right)
            parent->right = newNode;
         // If the right child of the parent node is empty, make the new node the right child
        else
        {
            parent = q.front();
            q.pop();                                                                          
            parent->left = newNode;
        }
    }

    // Return the root node
    return root;
}




    int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node *root = createTree(arr);
    cout << "root = " << root->data << endl;
    cout << "preorder traversal of the constructed tree is: \n";
    preorder(root);
    cout << "\n";

    return 0;
}

