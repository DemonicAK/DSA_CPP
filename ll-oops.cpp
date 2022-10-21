#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class to
// implement a linked list.
class Linkedlist
{
    Node *head;

public:
    // Default constructor
    Linkedlist() { head = NULL; }

    // Function to insert a
    // Node at the end of the
    // linked list.
    // void insertNode(int);
    void insertNode(int val, int pos)
    {

        // if (pos >= length(head) + 1)
        // {
        //     pos = length(head) + 1;
        // }

        Node *n = new Node(val);
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
                Node *temp = head;
                int temppos = 1;
                while (temppos != pos - 1)
                {
                    temp = temp->next;
                    temppos++;
                }
                Node *saver = temp->next;
                temp->next = n;
                n->next = saver;
            }
        }
    }

    void deletePos(int pos)
    {
        if (head == NULL)
        {
            return;
        }
        // cout << pos << "\n";

        // if (pos >= length(head))
        // {
        //     pos = length(head);
        // }
        if (pos == 1)
        {
            // del_head(head)
            Node *v = head;
            head = head->next;
            delete v;
        }
        else
        {
            Node *temp = head;
            int temppos = 1;
            while (temppos != pos - 1)
            {
                temp = temp->next;
                temppos++;
            }
            Node *v = temp->next;
            temp->next = temp->next->next;
            delete v;
        }
    }
    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // Node at given position
    void deleteNode(int val)
    {
        if (head == NULL)
            return;

        if (head->data == val)
        {
            head = head->next;

            return;
        }

        else
        {
            Node *temp = head;
            while (temp->next->data != val)
            {
                temp = temp->next;
                if (temp->next == NULL)
                {
                    return;
                }
            }
            Node *todel = temp->next;
            temp->next = temp->next->next;
            delete todel;
        }
    }

    void reverse()
    {
        // Initialize current, previous and next pointers
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    void reversek(int k)
    {
        
    }
};

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node *temp = head;

    // Check for empty list.
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Linkedlist list;

    // Inserting nodes
    list.insertNode(1, 1);
    list.insertNode(2, 1);
    list.insertNode(3, 3);
    list.insertNode(4, 4);

    cout << "Elements of the list are: ";

    // Print the list
    list.printList();
    cout << endl;

    // Delete Node at position 2.
    list.deleteNode(5);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;

    cout << "Elements after reverse:";
    list.reverse();
    list.printList();
    cout << "\n";

    return 0;

    return 0;
}