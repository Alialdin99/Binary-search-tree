#include "BST.h"
#include <iostream>

BST::studentNode* BST::insert(studentNode* node, int id, string studentName, string deptName, float studentGPA)
{
    if(node == nullptr)
   {
        studentNode* newNode = new studentNode(id,studentName,deptName,studentGPA);
        return newNode;
   }

    else if(id < node->id)
    {
        node->left = insert(node->left, id, studentName, deptName, studentGPA);
    }
    else if (id > node->id)
    {
        node->right = insert(node->right, id, studentName, deptName, studentGPA);
    }

    return node;
}

void BST::insert(int id, string studentName, string deptName, float studentGPA)
{
    root = insert(root, id,  studentName,  deptName,  studentGPA);
}

void BST::search(studentNode *root, int studentID)
{
    if(root == nullptr)
    {
        cout<<"Student not found"<<endl;
        return;
    }
    else if(root -> id == studentID)
    {
        cout<<"Name: "<<root -> name<<endl;
        cout<<"ID: "<<root -> id<<endl;
        cout<<"Department: "<<root -> department<<endl;
        cout<<"GPA: "<<root -> gpa<<endl;
        return;
    }
    else if(root -> id > studentID)
    {
        search(root->left,studentID);
    }
    else
    {
        search(root -> right, studentID);
    }
}

void BST::search(int studentID)
{
    search(root, studentID);
}

void BST::print(studentNode* node)
{
    if(node == nullptr)
    {
        return;
    }

    print(node->left);
    cout<<"ID: "<<node->id<<" ";
    cout<<"Name: "<<node->name<<" ";
    cout<<"Department: "<<node->department<<" ";
    cout<<"GPA: "<<node->gpa<<" ";
    cout<<endl;
    print(node->right);
}

void BST::print()
{
    print(root);
}

BST::studentNode* BST::minimumID(studentNode *node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    else if(node ->left == nullptr)
    {
        return node;
    }
    else
    {
        minimumID(node ->left);
    }
}

BST::studentNode* BST::minimumID()
{
    minimumID(root);
}

BST::studentNode* BST::maximumID(studentNode* node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    else if(node ->right == nullptr)
    {
        return node;
    }
    else
    {
        minimumID(node ->right);
    }
}

BST::studentNode* BST::maximumID()
{
    maximumID(root);
}

BST::studentNode* BST::remove(studentNode* node,int studentID) {
    if (node == nullptr)
        return nullptr;

    if (studentID < node->id)
        node->left = remove(node->left, studentID);
    else if (studentID > node->id)
        node->right = remove(node->right, studentID);

    else
    {
        if(node -> left == nullptr && node -> right == nullptr) // if it's a leaf node
        {
            node = nullptr;
        }
        else if (node -> left != nullptr && node -> right == nullptr)
        {
            node -> id = node -> left->id;
            node -> left = nullptr;
        }
        else if (node -> left == nullptr && node -> right != nullptr)
        {
            node -> id = node -> right->id;
            node -> right = nullptr;
        }
        else
        {
            studentNode* maxID = maximumID(node -> left);
            node -> id = maxID ->id;
            node->left = remove(node->left,maxID->id);
        }
    }
    return node;
}

BST:: studentNode* BST:: remove(int studentID)
{
    remove(root,studentID);
}

