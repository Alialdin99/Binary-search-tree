

#ifndef BST_BST_H
#define BST_BST_H

#include <string>

using namespace std;

class BST {
private:
    class studentNode
    {
    public:
        int id;
        string name;
        string department;
        float gpa;
        studentNode* left;
        studentNode* right;
        studentNode(int studentID, string studentName,string deptName, float studentGPA) {
            id = studentID;
            name = studentName;
            department = deptName;
            gpa = studentGPA;
            left = nullptr;
            right = nullptr;
        }
    };
    studentNode* root;

public:
    BST()
    {
        root = nullptr;
    }
    studentNode* insert( studentNode* node,int id, string studentName,string deptName, float studentGPA);
    void insert(int id, string studentName,string deptName, float studentGPA);
    void search(studentNode* root, int studentID);
    void search(int studentID);
    void print(studentNode* node);
    void print();
    studentNode* minimumID(studentNode* node);
    studentNode* minimumID();
    studentNode* maximumID(studentNode* node);
    studentNode* maximumID();
    studentNode* remove(studentNode* node ,int studentID);
    studentNode* remove(int studentID);

};


#endif //BST_BST_H
