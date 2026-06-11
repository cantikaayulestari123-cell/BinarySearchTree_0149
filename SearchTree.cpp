//BinarySearchTree_149
#include <iostream>
#include <string>
using namespace std; 

class Node
{
public:
    string info;
    Node *leftchild;
    Node *rightchild;

    // constructor for the node class
    Node(string i, Node *l, Node *r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class binarytree
{
public:
     Node *ROOT;

     binarytree()
    {
        ROOT = NULL;
    }


void insert(string element)
{
     Node *newNode = new Node(element, NULL, NULL);

     newNode->info = element;
     newNode->leftchild = NULL;
     newNode->rightchild = NULL;

     Node *parent = NULL;
     Node *currentNode = NULL;

     search(element, parent, currentNode);

       if (parent == NULL)
        {
            ROOT = newNode;
            return;
        }

        if(element < parent->info)
        {
            parent->leftchild = newNode;
        }
        else if(element > parent->info)
        {
            parent->rightchild = newNode;
        }

}

    // this function searches the current node of the specified node
    // as well as the current node of its parent
    void search(string element, Node *&parent, Node *&currentnode)
    {
        currentnode = ROOT;
        parent = NULL;

        while (currentnode != NULL && currentnode->info != element)
        {
            parent = currentnode;

            if (element < currentnode->info)
                currentnode = currentnode->leftchild;
            else
                currentnode = currentnode->rightchild;
        }
    }

    void inorder(Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }

        if(ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }

    }
};




