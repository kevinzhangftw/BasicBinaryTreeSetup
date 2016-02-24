//
//  bst.cpp
//  cmpt225lab5
//
//  Created by Kevin Zhang on 2016-02-23.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#include "bst.hpp"


// Default Constructor
// PRE:
// POST: root set to NULL
BST::BST()
{
    root = NULL;
}

// De-allocates dynamic memory associated with tree
// PRE:
// POST:
BST::~BST()
{
    
}

// Insert value in tree maintaining bst property
// PRE:
// PARAM: value = value to be inserted
// POST: Value is inserted, in order, in tree
void BST::Insert(int value)
{
    Node* newNode = new Node(value);
    Node* parent = root;
    Node* pos = root;
    bool isLeft = true;
    // Set new root if tree is empty
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        // Find parent of new node
        while (pos != NULL)
        {
            parent = pos;
            if (value < parent->data)
            {
                pos = parent->left;
                isLeft = true;
            }
            else
            {
                pos = parent->right;
                isLeft = false;
            }
        }
        // Insert new node
        if (isLeft)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }
}

// Searches tree for target
// PRE:
// PARAM: target = value to be found
// POST: Returns true iff target is in tree
bool BST::Search(int target)
{
    return SearchHelper(root, target);
}

bool BST::SearchHelper(Node* nd, int target)
{
    if (nd == NULL) {
        return false;
    }
    if (nd->data == target) {
        return true;
    }else{
        if (nd->data > target) {
            SearchHelper(nd->left, target);
        }else{
            SearchHelper(nd->right, target);
        }
    }
    return false;
}

// Prints contents of tree pre, in, post order
// PRE:
// POST: Prints contents of tree three times:
//       pre order, in order and post order
void BST::Print()
{
    cout << "Pre Order" << endl;
    PreOrderPrint(root);
    cout << endl << "In Order" << endl;
    InOrderPrint(root);
    cout << endl << "Post Order" << endl;
    PostOrderPrint(root);
}

// Performs an in-order traversal of tree
// PRE:
// POST: Prints contents of tree in order
void BST::InOrderPrint(Node* nd)
{
    if (nd != NULL) {
        InOrderPrint(nd->left);
        cout << nd->data <<  " ";
        InOrderPrint(nd->right);
    }
}

// Performs a pre-order traversal of tree
// PRE:
// POST: Prints contents of tree with pre order traversal
void BST::PreOrderPrint(Node* nd)
{
    if (nd != NULL) {
        cout << nd->data <<  " ";
        InOrderPrint(nd->left);
        InOrderPrint(nd->right);
    }
}

// Performs an post-order traversal of tree
// PRE:
// POST: Prints contents of tree with post order traversal
void BST::PostOrderPrint(Node* nd)
{
    if (nd != NULL) {
        InOrderPrint(nd->left);
        InOrderPrint(nd->right);
        cout << nd->data <<  " ";
    }
}
